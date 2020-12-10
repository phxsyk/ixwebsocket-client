cmake_minimum_required(VERSION 2.8.9)
if (WIN32)
    set(CMAKE_GENERATOR_PLATFORM win32)
endif (WIN32)

project (ixwebsocket-client)

# vcpkg installation directory
if (WIN32)
  set ( VCPKG_DIR $ENV{USERPROFILE}/Desktop/Programlar/vcpkg)
endif (WIN32)

if (UNIX)
  set ( VCPKG_DIR $ENV{HOME}/downloads/vcpkg)
endif (UNIX)
aditional

# directories and additional libraries
if (WIN32)
    include_directories(${VCPKG_DIR}/installed/x86-windows/include)

    set ( PROJECT_LINK_LIBS ixwebsocket.lib mbedcrypto.lib mbedtls.lib zlibd.lib crypt32.lib )
    link_directories(${VCPKG_DIR}/installed/x86-windows/debug/lib)
endif (WIN32)

if (UNIX)
    include_directories(${VCPKG_DIR}/installed/x64-linux/include)

    set ( PROJECT_LINK_LIBS libixwebsocket.a libssl.a libcrypto.a libz.a -lpthread -ldl)
    link_directories(${VCPKG_DIR}/installed/x64-linux/lib)
endif (UNIX)

# compile
add_executable(ixwebsocket-client main.cpp)

# link
target_link_libraries(ixwebsocket-client ${PROJECT_LINK_LIBS})