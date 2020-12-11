# IXWebsocket - Websocket Client  

Websocket client based on [IXWebsocket](https://github.com/machinezone/IXWebSocket) library

## Prerequisities
- vcpkg
- ixwebsocket (vcpkg install ixwebsocket[ssl])

**vcpkg** cmake toolchain may not work, so in order to find *include* and *lib* directories edit paths after __*USERPROFILE*__ (__*HOME*__ in Linux) varible in CMakeLists.txt according to your filesystem locations.

## Building
- mkdir build
- cd build
- cmake ..
- make (Linux[g++])
- msbuild ixwebsocket-client.sln (Windows[msvc])

## Run
```
ixwebsocket-client ws://127.0.0.1:3002
```
