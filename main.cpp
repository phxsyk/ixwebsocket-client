#include <iostream>
#ifdef _WIN32
  #include <ixwebsocket/IXNetSystem.h>
#endif
#include <ixwebsocket/IXWebSocket.h>

int main(int argc, char *argv[])
{

#ifdef _WIN32
  ix::initNetSystem();
#endif

  // Our websocket object
  ix::WebSocket webSocket;

  if (argc < 2)
  {
    std::cout << "Usage: ixwebsocket-client <url>\n";
    return 1;
  }
  std::cout << "-> Connecting to " << argv[1] << " ..." << std::endl;
  std::string url(argv[1]);
  webSocket.setUrl(url);

  webSocket.enableAutomaticReconnection(); // turn on

  // Optional heart beat, sent every 45 seconds when there is not any traffic
  // to make sure that load balancers do not kill an idle connection.
  webSocket.setPingInterval(45);

  // Per message deflate connection is enabled by default. You can tweak its parameters or disable it
  webSocket.disablePerMessageDeflate();

  // Setup a callback to be fired when a message or an event (open, close, error) is received
  webSocket.setOnMessageCallback([&webSocket](const ix::WebSocketMessagePtr &msg) {
    if (msg->type == ix::WebSocketMessageType::Message)
    {
      std::cout << "# Received: \"" << msg->str << "\"" << std::endl;
    }
    else if (msg->type == ix::WebSocketMessageType::Open)
    {
      std::cout << "# Connected." << std::endl;
    }
    else if (msg->type == ix::WebSocketMessageType::Pong)
    {
      std::cout << "# Pong" << std::endl;
    }
  });

  // Now that our callback is setup, we can start our background thread and receive messages
  webSocket.connect(3);
  std::string msg = "Hello!";
  webSocket.send(msg);
  std::cout << "# Sent: \"" << msg << "\"" << std::endl;
  //webSocket.sendBinary("some serialized binary data");
  webSocket.run();

  webSocket.stop();
}
