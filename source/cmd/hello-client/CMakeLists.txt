set(APP helloclient)
set(SRC main.cpp)
add_executable(${APP} ${SRC})
target_link_libraries(${APP} PUBLIC "-static"
    gencpp
    thrift
    pthread
)