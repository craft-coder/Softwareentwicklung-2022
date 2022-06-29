cmake_minimum_required(VERSION 3.15)

project(RaytracingExample LANGUAGES CXX VERSION 0.0.1)

add_subdirectory(src)
add_subdirectory(submodules/googletest EXCLUDE_FROM_ALL)
add_subdirectory(test)
