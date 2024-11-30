import subprocess
import os
import stat

id_certificate = '''
prompt              = no
distinguished_name  = req_distinguished_name
[ req_distinguished_name ]
countryName          = DE
stateOrProvinceName  = BY
localityName         = Munich
organizationName     = TUM
emailAddress         = {name1}@tum.de
commonName           = {name2}
'''

# create folder 'database'
os.makedirs("cert/ca/database", exist_ok=True)

# we create 'index' and 'serial' to keep track of the certificates we made
with open("cert/ca/database/index", "w") as f1:
    pass

with open("cert/ca/database/serial", "w") as f2:
    f2.write("01")

# create 'private' to store private information (keys)
os.makedirs("cert/ca/private", exist_ok=True)

# Create a private key and certificate (Identity CA)

subprocess.run(
    [
        'openssl',
        'req',
        '-x509',
        '-newkey',
        'rsa:4096',
        '-keyout',
        'cert/ca/private/IdentityCAKey.pem',
        '-out',
        'cert/ca/IdentityCACert.pem',
        '-sha256',
        '-days',
        '3650',
        '-nodes',
        '-subj',
        "/C=DE/ST=BY/L=Munich/O=TUM/OU=TUM/CN=IdentityCA"
    ]
)

# Change with the names of real DPs
dp_names = ["Alice", "Bob", "Trudy"]

# make directories for all DPs and make a .cnf file
for i in dp_names:
    # Create folder
    os.makedirs(f"cert/identities/{i}/private", exist_ok=True)

    # Create .cnf file of the DP
    with open(f"cert/identities/{i}/{i}.cnf", "w") as f3:
        f3.write(id_certificate.format(name1=i.lower(), name2=i))

    # Create certificate
    subprocess.run(
        [
            "openssl",
            "req",
            "-nodes",
            "-new",
            "-newkey",
            "rsa:2048",
            "-config",
            f"cert/identities/{i}/{i}.cnf",
            "-keyout",
            f"cert/identities/{i}/private/{i}Key.pem",
            "-out",
            f"cert/identities/{i}/{i}.csr"
        ]
    )

    # Sign the new certificate with the IdentityCA's certificate
    subprocess.run(
        [
            "openssl",
            "x509",
            "-req",
            "-days",
            "730",
            "-text",
            "-CAserial",
            "cert/ca/database/serial",
            "-CA",
            "cert/ca/IdentityCACert.pem",
            "-CAkey",
            "cert/ca/private/IdentityCAKey.pem",
            "-in",
            f"cert/identities/{i}/{i}.csr",
            "-out",
            f"cert/identities/{i}/{i}.pem",
        ]
    )

# Create Permissions CA certificate
subprocess.run(
    [
        'openssl',
        'req',
        '-x509',
        '-newkey',
        'rsa:4096',
        '-keyout',
        'cert/ca/private/PermissionsCAKey.pem',
        '-out',
        'cert/ca/PermissionsCACert.pem',
        '-sha256',
        '-days',
        '3650',
        '-nodes',
        '-subj',
        "/C=DE/ST=BY/L=Munich/O=TUM/OU=TUM/CN=PermissionsCA"
    ]
)

os.makedirs("xml/signed", exist_ok=True)

# sign the governance document
subprocess.run(
    [
        "openssl",
        "smime",
        "-sign",
        "-in",
        "xml/governance_document.xml",
        "-text",
        "-out",
        "xml/signed/Signed_Governance.p7s",
        "-signer",
        "cert/ca/PermissionsCACert.pem",
        "-inkey",
        "cert/ca/private/PermissionsCAKey.pem"
    ]
)

# sign the governance document of Trudy (incompatible with Alice and Bob)
subprocess.run(
    [
        "openssl",
        "smime",
        "-sign",
        "-in",
        "xml/governance_document.xml",
        "-text",
        "-out",
        "xml/signed/Signed_Governance_false.p7s",
        "-signer",
        "cert/ca/IdentityCACert.pem",
        "-inkey",
        "cert/ca/private/IdentityCAKey.pem"
    ]
)

# sign the permission documents of all DPs
for i in dp_names:
    if i != 'Trudy':
        subprocess.run(
            [
                "openssl",
                "smime",
                "-sign",
                "-in",
                f"xml/permissions_document_{i.lower()}.xml",
                "-text",
                "-out",
                f"xml/signed/Signed_Permissions_{i.lower()}.p7s",
                "-signer",
                "cert/ca/PermissionsCACert.pem",
                "-inkey",
                "cert/ca/private/PermissionsCAKey.pem"
            ]
        )

# Sign Trudy's permissions document (should be signed with the same certificate that we signed the Trudy's governance document with)
subprocess.run(
    [
        "openssl",
        "smime",
        "-sign",
        "-in",
        f"xml/permissions_document_trudy.xml",
        "-text",
        "-out",
        f"xml/signed/Signed_Permissions_trudy.p7s",
        "-signer",
        "cert/ca/IdentityCACert.pem",
        "-inkey",
        "cert/ca/private/IdentityCAKey.pem"
    ]
)
