########## Benchmarkr Tests ##########

###### Integration Tests ######
add_executable(elk_client_tests elk_int_test.cpp)
target_precompile_headers(elk_client_tests PUBLIC elk_int_test_pch.h)
target_link_libraries(elk_client_tests PUBLIC elk-cpp-client)
