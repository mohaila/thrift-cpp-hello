#include <HelloService.h>
#include <thrift/TProcessor.h>

using apache::thrift::TConnectionInfo;
using helloservice::HelloServiceIf;
using helloservice::HelloServiceIfFactory;

class HelloServicerFactory : virtual public HelloServiceIfFactory {
 public:
  virtual ~HelloServicerFactory() = default;
  virtual HelloServiceIf* getHandler(const TConnectionInfo& connInfo);
  virtual void releaseHandler(HelloServiceIf* handler);
};