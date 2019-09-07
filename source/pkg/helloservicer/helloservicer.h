#include <HelloService.h>

using helloservice::HelloRequest;
using helloservice::HelloResponse;
using helloservice::HelloServiceIf;

class HelloServicer : public HelloServiceIf {
 public:
  HelloServicer() = default;
  virtual void hello(HelloResponse& response, const HelloRequest& request);
};