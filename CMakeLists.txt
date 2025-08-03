cmake_minimum_required(VERSION 4.0.0)

project("BlockApp" CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED on)

file(GLOB PROJECT_SOURCE_FILES ./*cpp)
file(GLOB PROJECT_HEADER_FILES ./*hpp ./GL_Utils/*hpp ./Shaders/*hpp ./Shapes/*hpp)

find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)
find_package(GLEW REQUIRED)

add_executable(${PROJECT_NAME} ${PROJECT_SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} glfw GL GLEW)


