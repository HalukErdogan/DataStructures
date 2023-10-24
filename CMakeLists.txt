# cmake version
cmake_minimum_required(VERSION 3.20)

# project name
project(ds)

# include external libraries
add_subdirectory(external) 

# data structure library (ds)
add_library(ds STATIC src/ds/vector)
target_include_directories(ds PUBLIC include)

# test
add_subdirectory(test)

# benchmark
add_subdirectory(benchmark)