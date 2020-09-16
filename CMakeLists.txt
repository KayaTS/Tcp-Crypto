cmake_minimum_required(VERSION 3.0.0)
project(Tcp-Crypto VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(server server.cpp Crypto.cpp) 
add_executable(client client.cpp Crypto.cpp)   
find_package(OpenSSL REQUIRED)
target_link_libraries(server OpenSSL::SSL)
target_link_libraries(client OpenSSL::SSL)
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
