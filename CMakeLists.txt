cmake_minimum_required(VERSION 3.18)
project(udp_over_tunnel)

set(CMAKE_CXX_STANDARD 11)

# Packages
find_package(OpenSSL REQUIRED)
find_package(libhv CONFIG REQUIRED)

add_executable(udp_over_tunnel main.cpp include/tunnel.h include/transport.h test/test.h wsTunnel.cpp include/wsTunnel.h include/session.h transport.cpp include/mapping.h server/serverSession.h server/serverSession.cpp client/clientSession.h client/clientSession.cpp client/clientMapping.h client/clientMapping.cpp client/utils.cpp client/clientUtils.cpp client/clientUtils.h Utils.cpp Utils.h)

# Link
target_link_libraries(udp_over_tunnel PRIVATE OpenSSL::SSL OpenSSL::Crypto)
target_link_libraries(udp_over_tunnel PRIVATE hv_static)