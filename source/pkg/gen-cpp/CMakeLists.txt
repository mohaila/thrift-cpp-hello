set(PKG gencpp)
set(PKGSRC helloservice_constants.cpp
    HelloService_server.skeleton.cpp
    helloservice_types.cpp
    HelloService.cpp
)
add_library(${PKG} STATIC ${PKGSRC})