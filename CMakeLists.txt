cmake_minimum_required(VERSION 3.20)

project(language)

set(CMAKE_CXX_STANDARD 20)

add_executable(language src/main.cpp)
target_compile_features(language PRIVATE cxx_std_20)

