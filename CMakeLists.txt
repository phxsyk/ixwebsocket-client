cmake_minimum_required(VERSION 2.8.9)
if (WIN32)
    set(CMAKE_GENERATOR_PLATFORM win32)
endif (WIN32)

project (ixwebsocket-client)

if (WIN32)
    #cmake_build_type(Debug)

    include_directories($ENV{USERPROFILE}/Desktop/Programlar/vcpkg/installed/x86-windows/include)

    set ( PROJECT_LINK_LIBS ixwebsocket.lib mbedcrypto.lib mbedtls.lib zlibd.lib )
    link_directories($ENV{USERPROFILE}/Desktop/Programlar/vcpkg/installed/x86-windows/debug/lib)
endif (WIN32)

if (UNIX)
    include_directories($ENV{HOME}/downloads/vcpkg/installed/x64-linux/include)

    set ( PROJECT_LINK_LIBS libixwebsocket.a libssl.a libcrypto.a libz.a )
    link_directories($ENV{HOME}/downloads/vcpkg/installed/x64-linux/lib)
endif (UNIX)


add_executable(ixwebsocket-client main.cpp)
if (WIN32)
    target_link_libraries(ixwebsocket-client ${PROJECT_LINK_LIBS})
endif (WIN32)
if (UNIX)
    target_link_libraries(ixwebsocket-client ${PROJECT_LINK_LIBS} -lpthread -ldl)
endif (UNIX)
