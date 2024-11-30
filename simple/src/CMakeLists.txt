cmake_minimum_required(VERSION 3.25)
project(Security_Project)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "C:/Program Files/rti_connext_dds-7.2.0/resource/cmake")
set(OPENSSL_ROOT_DIR "C:/Users/Lenovo/Documents/rti_workspace/vcpkg/vcpkg/packages/openssl_x64-windows")

find_package(RTIConnextDDS REQUIRED COMPONENTS core security_plugins)
file(GLOB_RECURSE CXX_FILES "Data_Types/*.cxx")

#Alice
add_executable(alice_dp dps/Alice/alice_dp.cpp ${CXX_FILES})
target_include_directories(alice_dp PRIVATE ${PROJECT_SOURCE_DIR})
target_link_libraries(alice_dp PRIVATE RTIConnextDDS::cpp2_api RTIConnextDDS::security_plugins)

#Bob
add_executable(bob_dp dps/Bob/bob_dp.cpp ${CXX_FILES})
target_include_directories(bob_dp PRIVATE ${PROJECT_SOURCE_DIR})
target_link_libraries(bob_dp PRIVATE RTIConnextDDS::cpp2_api RTIConnextDDS::security_plugins)

#Trudy
add_executable(trudy_dp dps/Trudy/trudy_dp.cpp ${CXX_FILES})
target_include_directories(trudy_dp PRIVATE ${PROJECT_SOURCE_DIR})
target_link_libraries(trudy_dp PRIVATE RTIConnextDDS::cpp2_api RTIConnextDDS::security_plugins)

file(COPY "../InformationModel" DESTINATION  ${CMAKE_CURRENT_BINARY_DIR})
