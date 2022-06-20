add_library(RaytracerLib Vec3.cpp)
target_include_directories(RaytracerLib PUBLIC ${CMAKE_CURRENT_LIST_DIR})
set_target_properties(RaytracerLib PROPERTIES CXX_STANDARD 17)

add_executable(RaytracerExecutable main.cpp)
target_link_libraries(RaytracerExecutable PRIVATE RaytracerLib)
