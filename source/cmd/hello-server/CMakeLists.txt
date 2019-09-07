set(APP helloserver)
set(SRC main.cpp)
add_executable(${APP} ${SRC})
target_link_libraries(${APP} PUBLIC "-static" 
    gencpp 
    helloservicer
    thrift
    pthread)