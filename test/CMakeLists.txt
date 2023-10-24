enable_testing()

add_executable(
  vector_test
  vector_test.cc
)
target_link_libraries(
  vector_test
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(hello_test)