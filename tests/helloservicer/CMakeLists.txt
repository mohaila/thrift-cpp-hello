set(TEST testhelloservicer)
set(TESTSRC main.cpp)
add_executable(${TEST} ${TESTSRC})
target_link_libraries(${TEST} PUBLIC "-static"
    helloservicer
    gencpp
    gtest
    -Wl,--whole-archive -lpthread -Wl,--no-whole-archive
)

add_test(NAME ${TEST}
    COMMAND ${TEST}
)