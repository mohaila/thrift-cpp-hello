#include <thrift/stdcxx.h>
#include <thrift/transport/TSocket.h>
#include <iostream>

#include "helloservicer.h"
#include "helloservicerfactory.h"

using apache::thrift::stdcxx::dynamic_pointer_cast;
using apache::thrift::stdcxx::shared_ptr;
using apache::thrift::transport::TSocket;
using std::cout;
using std::endl;

HelloServiceIf* HelloServicerFactory::getHandler(
    const TConnectionInfo& connInfo) {
  shared_ptr<TSocket> sock = dynamic_pointer_cast<TSocket>(connInfo.transport);
  cout << "Incoming connection" << endl;
  cout << "\tSocketInfo: " << sock->getSocketInfo() << endl;
  cout << "\tPeerHost: " << sock->getPeerHost() << endl;
  cout << "\tPeerAddress: " << sock->getPeerAddress() << endl;
  cout << "\tPeerPort: " << sock->getPeerPort() << endl;

  return new HelloServicer;
}

void HelloServicerFactory::releaseHandler(HelloServiceIf* handler) {
  delete handler;
}