#include <gtest/gtest.h>

#include <gen-cpp/HelloService.h>
#include <helloservicer/helloservicer.h>

using helloservice::ExceptionError;
using helloservice::HelloRequest;
using helloservice::HelloResponse;
using helloservice::InvalidOperation;
using testing::InitGoogleTest;
using testing::Test;

class HelloServicerTester : public Test {
 public:
  void SetUp() { servicer = new HelloServicer; }

  void TearDown() { delete servicer; }

  HelloServicer* servicer;
};

TEST_F(HelloServicerTester,
       HelloReturnsMessageWhenCalledWithValidVersionAndName) {
  HelloRequest request;
  request.name = "World!";
  HelloResponse response;

  servicer->hello(response, request);
  ASSERT_EQ(response.version, 1);
  ASSERT_EQ(response.message, "Hello World!");
}

TEST_F(HelloServicerTester, HelloExceptionWhenCalledWithInvalidVersion) {
  HelloRequest request;
  request.version = 0;
  request.name = "World!";
  HelloResponse response;

  ASSERT_THROW(servicer->hello(response, request), InvalidOperation);

  try {
    servicer->hello(response, request);
  } catch (InvalidOperation& io) {
    ASSERT_EQ(io.error, ExceptionError::InvalidVersion);
  }
}

TEST_F(HelloServicerTester, HelloExceptionWhenCalledWithInvalidName) {
  HelloRequest request;
  HelloResponse response;

  ASSERT_THROW(servicer->hello(response, request), InvalidOperation);
  try {
    servicer->hello(response, request);
  } catch (InvalidOperation& io) {
    ASSERT_EQ(io.error, ExceptionError::InvalidRequest);
  }
}

int main(int argc, char** argv) {
  InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}