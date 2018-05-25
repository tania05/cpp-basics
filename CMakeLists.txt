cmake_minimum_required(VERSION 3.10 FATAL_ERROR)
project(cpp_basics LANGUAGES CXX)

add_executable(random app/test_random.cpp lib/random.cpp include/ra/random.hpp)
add_executable(rational app/test_rational.cpp include/ra/rational.hpp)

target_include_directories(random PUBLIC include "${CMAKE_CURRENT_BINARY_DIR}/include")
target_include_directories(rational PUBLIC include "${CMAKE_CURRENT_BINARY_DIR}/include")

