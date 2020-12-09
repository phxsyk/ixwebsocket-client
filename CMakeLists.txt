cmake_minimum_required(VERSION 2.8.9)
project (ixwebsocket-client)

include_directories(/root/downloads/vcpkg/installed/x64-linux/include)

set ( PROJECT_LINK_LIBS libixwebsocket.a libssl.a libcrypto.a libz.a )
link_directories(/root/downloads/vcpkg/installed/x64-linux/lib)

add_executable(ixwebsocket-client main.cpp)
target_link_libraries(ixwebsocket-client ${PROJECT_LINK_LIBS} -lpthread -ldl)