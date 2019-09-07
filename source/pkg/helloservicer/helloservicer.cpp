#include <thrift/TToString.h>
#include <thrift/concurrency/PlatformThreadFactory.h>
#include <thrift/concurrency/ThreadManager.h>
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/server/TSimpleServer.h>
#include <thrift/server/TThreadPoolServer.h>
#include <thrift/server/TThreadedServer.h>
#include <thrift/stdcxx.h>
#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/TSocket.h>
#include <thrift/transport/TTransportUtils.h>

#include <sstream>
#include <stdexcept>
#include <string>

#include "helloservicer.h"

using helloservice::ExceptionError;
using helloservice::InvalidOperation;
using std::string;

void HelloServicer::hello(HelloResponse& response,
                          const HelloRequest& request) {
  if (request.version != 1) {
    InvalidOperation io;
    io.error = ExceptionError::InvalidVersion;
    throw io;
  }

  auto name = request.name;
  if (name.size() == 0) {
    InvalidOperation io;
    io.error = ExceptionError::InvalidRequest;
    throw io;
  }

  string message = "Hello ";
  response.message = message + name;
}
