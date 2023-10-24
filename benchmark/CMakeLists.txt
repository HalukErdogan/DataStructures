add_executable(
    vector_benchmark
    ds/vector_benchmark.cc
)

target_link_libraries(
    vector_benchmark
    ds
    benchmark::benchmark_main
)