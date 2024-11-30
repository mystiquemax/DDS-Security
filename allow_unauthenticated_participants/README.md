#  Files needed for secure communication

* **Permissions document**: Each DP provides its permissions in the specified domains (signed by Permissions CA / in the XML file: **dds.sec.access.permissions**)
* **Governance document**: All DPs provide the same governance document, which provides information about if/how the domains and topics are secured (signed by Permissions CA / in the XML file: **dds.sec.access.governance**)
* **Private Key**: Each DP needs its own unique PK for authentication (in the XML file: **dds.sec.auth.private_key**)
* **Identity Certificate**: Each DP has a unique certificate to prove his identity (signed by Identity CA / in the XML file: **dds.sec.auth.identity_certificate**).
* **Identity CA**: Identity CA certificate. Used to verify that Identity Certificates of the DP are legitimate (Usually all DP load the same certificate / in the XML: **dds.sec.auth.identity_ca**).
* **Permissions CA**: Permissions CA certificate. Used to verify that the Governance and Permissions Document are legitimate (All DPs load the same certificate / in the XML: **dds.sec.access.permissions_ca**).

# Requirements 

* OpenSSL
* RTI Secure Plugins
* Python (to run gen_secure.py)

# How to set up OpenSSL with Windows using *vcpkg* (Recommended)

* Download vcpkg from https://github.com/Microsoft/vcpkg/
* cd vcpkg (go to where you downloaded/cloned vcpkg)
* .\\bootstrap-vcpkg.bat
* .\\vcpkg integrate install
* .\\vcpkg search openssl (not necessary)
* .\\vcpkg install openssl (it may take some time)

Then in the CMakeLists.txt you should set OPENSSL_ROOT_DIR to the path to OpenSSL directory.

# How to set up OpenSSL with Windows using *Chocolatey* or *Scoop* (you have to set the environment variable *OPENSSL_ROOT_DIR* on your own)

* *choco install openssl* for Chocolatey
* *scoop install openssl* for Scoop
* Follow the steps

To use OpenSSL directly, you can open *Win64 OpenSSL Command Prompt*.

# Steps

*gen_secure.py* does all the following for this project. If you would like to do it yourself or to understand how does it work, I leave the step below: 

### Identity CA

1. Create .cnf file for the root certificate (in the project : cert\IdentityCA.cnf). See [Notes](#my-notes) for a template and instructions. Set *dir*, *private key*, *certificate* and *req_distinguished_name* (and also other fields if needed) to suit your project.
2. Use the commands to create database files to keep track of the issued certificates: 
 * *mkdir cert\ca\database* 
 * *type nul > cert\ca\database\index.txt*
 * *echo 01> cert\ca\database\serial*
3. Create a folder for private stuff (e.g. private keys):
 * *mkdir cert\ca\private*
 You may also want to limit the access to this folder.
4. This command with generate a root certificate that is valid for 10000 days (-days 1000) and a private key(-newkey rsa:2048) to it without a password:
 * *openssl req -nodes -x509 -days 10000 -text -sha256 -newkey rsa:2048 -keyout cert\{name-of-the-key}.pem -out cert\{name-of-the-certificate}.pem -config cert\IdentityCA.cnf*
5. Add the new Identity CA certificate to the XML file

### Identity Certificate

1. Create a .cnf file with the Domain Participant name (e.g. Alice.cnf)
2. Add this sample content to it:
>prompt              = no <br/>
>distinguished_name  = req_distinguished_name <br/>
> [ req_distinguished_name ] <br/>
> countryName          = DE <br />
> stateOrProvinceName  = BY <br />
> localityName         = Munich <br />
> organizationName     = TUM <br />
> emailAddress         = alice@tum.de <br />
> commonName           = Alice <br />
3. Generate key and CSR: 
   * *openssl req -nodes -new -newkey rsa:2048 -config cert\Alice.cnf -keyout cert\AliceKey.pem -out cert\Alice.csr*
4. Sign the CSR with your Identity CA:
   * *openssl ca -config cert\IdentityCA.cnf -days 10000 -in cert\Alice.csr -out cert\AliceCert.pem*
5. Add the new Identity CA certificate to the XML file
6. This step is repeated for all Domain Participants

### Permission CA

1. The following command will show you Alice's certificate. Copy the **Issuer** field and paste it in the permissions document (a .xml file) under **<subject_name>**:

*  *openssl x509 -in cert\AliceCert.pem -text -noout*

2. Create cert/PermissionsCA.cnf file (like IdentityCA.cnf). For template, see [Notes](#my-notes)

3. Create a Permissions Root certificate, and a private key from the .cnf file:
* *openssl req -nodes -x509 -days 1825 -text -sha256 -newkey rsa:2048 -keyout cert\PermissionsCAKey.pem -out cert\PermissionsCACert.pem -config cert\PermissionsCA.cnf*

4. Add the new Permissions Certificate to the XML file

### Permission Document and Governance Document

1. See *Security_Tests/xml* for the creation of the Permissions Document and Governance Document.
2. Sign the governance file with the Permissions Certificate:
* *openssl smime -sign -in xml\Governance.xml -text -out xml\signed\Signed_Governance.p7s -signer cert\PermissionsCACert.pem -inkey cert\PermissionsCAKey.pem*
3. Sign the permissions file with the Permisssions Certificate. This step is repeated for all Domain Participants:
* *openssl smime -sign -in xml\PermissionsAlice.xml -text -out xml\signed\Signed_PermissionsAlice.p7s -signer cert\PermissionsCACert.pem -inkey cert\PermissionsCAKey.pem*
3. Add the new Permissions Documents, and the Governance Document to the XML file

# Notes <a name="my-notes"> </a>

1. Template for root certificate (you may also use the site for instructions): https://jamielinux.com/docs/openssl-certificate-authority/appendix/root-configuration-file.html. 
2. The configuration of the security properties (e.g. which artifact belongs to which DP) through an XML file can be done directly with the declaration of the DP or in a separate QoS profile (this project uses the second option)
3. In this project we use a permissions document for each DP. It can be also used one permissions document for all DPs.
4. Useful links: 
 * **RTI Connext Secure Getting Started**: https://community.rti.com/static/documentation/connext-dds/7.2.0/doc/manuals/connext_dds_secure/getting_started_guide/index.html
 * **RTI Connext Secure User's Manual**: https://community.rti.com/static/documentation/connext-dds/7.2.0/doc/manuals/connext_dds_secure/users_manual/index.html

5.com.rti.serv.secure.authentication.key_establishment_algorithm to specify the key establishment algorithm

6.dds.sec.auth.password if the key of a participant is encrypted with password

7.com.rti.serv.secure.cryptography.rtps_protection_preshared_key