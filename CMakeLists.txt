cmake_minimum_required(VERSION 2.8.9)
project (ixwebsocket-client)

if (WIN32)
    #do something
endif (WIN32)

if (UNIX)
    include_directories($ENV{HOME}/downloads/vcpkg/installed/x64-linux/include)

    set ( PROJECT_LINK_LIBS libixwebsocket.a libssl.a libcrypto.a libz.a )
    link_directories($ENV{HOME}/downloads/vcpkg/installed/x64-linux/lib)
endif (UNIX)


add_executable(ixwebsocket-client main.cpp)
if (UNIX)
    target_link_libraries(ixwebsocket-client ${PROJECT_LINK_LIBS} -lpthread -ldl)
endif (UNIX)
