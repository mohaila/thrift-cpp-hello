#include <iostream>

#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/stdcxx.h>
#include <thrift/transport/TSocket.h>
#include <thrift/transport/TTransportUtils.h>

#include <HelloService.h>

using namespace std;
using namespace apache::thrift;
using namespace apache::thrift::protocol;
using namespace apache::thrift::transport;

using namespace helloservice;

int main() {
  stdcxx::shared_ptr<TTransport> socket(new TSocket("localhost", 9090));
  stdcxx::shared_ptr<TTransport> transport(new TBufferedTransport(socket));
  stdcxx::shared_ptr<TProtocol> protocol(new TBinaryProtocol(transport));
  HelloServiceClient client(protocol);

  try {
    transport->open();
    HelloRequest request;
    request.name = "World!";

    HelloResponse response;

    client.hello(response, request);
    cout << response.message << endl;

  } catch (InvalidOperation& io) {
    switch (io.error) {
      case ExceptionError::InvalidRequest:
        cerr << "Invalid request" << endl;
        break;
      case ExceptionError::InvalidVersion:
        cerr << "Invalid version" << endl;
        break;
    }
  } catch (TException& tx) {
    cout << "ERROR: " << tx.what() << endl;
  }
}
