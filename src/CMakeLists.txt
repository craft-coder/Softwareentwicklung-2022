add_library(RaytracerLib Vec3.cpp)
set_target_properties(RaytracerLib PROPERTIES CXX_STANDARD 17)

add_executable(RaytracerExecutable main.cpp)
target_link_libraries(RaytracerExecutable PRIVATE RaytracerLib)
