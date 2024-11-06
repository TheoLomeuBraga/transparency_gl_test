cmake_minimum_required(VERSION 3.0)
project(example_project)

#sdl
set(SDL_STATIC ON)
add_subdirectory(libs/SDL)

#exe
set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")
include_directories(src libs/SDL/include)

add_executable(test src/main.cpp)

find_package(OpenGL REQUIRED)
target_link_libraries(test SDL3::SDL3-static ${OPENGL_LIBRARIES})
#link_libraries(demo SDL3::SDL3-static)