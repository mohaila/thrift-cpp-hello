namespace cpp helloservice

enum ExceptionError {
    InvalidVersion = 1,
    InvalidRequest = 2,
}
struct HelloRequest {
    1: i32 version = 1,
    2: string name,
}

struct HelloResponse {
    1: i32 version = 1,
    2: string message,
}

exception InvalidOperation {
    1: i32 version = 1,
    2: ExceptionError error,
}

service HelloService {
    HelloResponse hello(1: HelloRequest request) throws (1: InvalidOperation error),
}