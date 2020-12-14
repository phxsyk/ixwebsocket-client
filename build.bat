RD /S /Q build
MKDIR build
CD build
cmake ..
msbuild ixwebsocket-client.sln
CD ..