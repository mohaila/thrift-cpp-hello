#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/server/TThreadedServer.h>
#include <thrift/transport/TBufferTransports.h>
#include <thrift/transport/TServerSocket.h>
#include <iostream>

#include <HelloService.h>
#include <helloservicer/helloservicerfactory.h>

using apache::thrift::protocol::TBinaryProtocolFactory;
using apache::thrift::server::TThreadedServer;
using apache::thrift::stdcxx::make_shared;
using apache::thrift::transport::TBufferedTransportFactory;
using apache::thrift::transport::TServerSocket;
using helloservice::HelloServiceProcessorFactory;
using std::cout;
using std::endl;

int main() {
  TThreadedServer server(make_shared<HelloServiceProcessorFactory>(
                             make_shared<HelloServicerFactory>()),
                         make_shared<TServerSocket>(9090),  // port
                         make_shared<TBufferedTransportFactory>(),
                         make_shared<TBinaryProtocolFactory>());

  cout << "Starting the server..." << endl;
  server.serve();
  cout << "Done." << endl;
  return 0;
}