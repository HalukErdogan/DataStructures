enable_testing()

add_executable(
  vector_test
  ds/vector_test.cc
)

target_link_libraries(
  vector_test
  ds
  GTest::gtest_main
)
    
include(GoogleTest)
gtest_discover_tests(vector_test)