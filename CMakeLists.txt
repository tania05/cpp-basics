cmake_minimum_required(VERSION 3.10 FATAL_ERROR)
project(lgg LANGUAGES CXX)
add_executable(linear_congruential_generator app/test_random.cpp lib/random.cpp include/ra/random.hpp)
target_include_directories(linear_congruential_generator PUBLIC include "${CMAKE_CURRENT_BINARY_DIR}/include")

