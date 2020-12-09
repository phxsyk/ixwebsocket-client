#include <iostream>
#include <ixwebsocket/IXWebSocket.h>

int main()
{

  // Our websocket object
  ix::WebSocket webSocket;

  std::string url("ws://127.0.0.1:8080/");
  webSocket.setUrl(url);

  webSocket.enableAutomaticReconnection(); // turn on

  // Optional heart beat, sent every 45 seconds when there is not any traffic
  // to make sure that load balancers do not kill an idle connection.
  webSocket.setPingInterval(45);

  // Per message deflate connection is enabled by default. You can tweak its parameters or disable it
  webSocket.disablePerMessageDeflate();

  // Setup a callback to be fired when a message or an event (open, close, error) is received
  webSocket.setOnMessageCallback([](const ix::WebSocketMessagePtr &msg) {
    if (msg->type == ix::WebSocketMessageType::Message)
    {
      std::cout << msg->str << std::endl;
    }
  });

  // Now that our callback is setup, we can start our background thread and receive messages
   webSocket.connect(3);
  webSocket.send("hello world");
  webSocket.sendBinary("some serialized binary data");
     webSocket.run();
  // webSocket.start();
  // getchar();
  
  // Send a message to the server (default to TEXT mode)
  webSocket.send("hello world");

  // The message can be sent in BINARY mode (useful if you send MsgPack data for example)
  webSocket.sendBinary("some serialized binary data");

  // ... finally ...

  getchar();
  // Stop the connection
  webSocket.stop();

  // getchar();
}
