add_library(RaytracerLib Vec3.cpp
                         Ray.cpp
                         Sphere.cpp
                         Hittables.cpp)
target_include_directories(RaytracerLib PUBLIC ${CMAKE_CURRENT_LIST_DIR})
target_compile_features(RaytracerLib PUBLIC cxx_std_17)

add_executable(RaytracerExecutable main.cpp)
target_link_libraries(RaytracerExecutable PRIVATE RaytracerLib)
