SET(PROJECT_NAME disp_image)

cmake_minimum_required(VERSION 3.0.0)
project(${PROJECT_NAME} VERSION 0.1.0)
add_executable(${PROJECT_NAME}.elf glad.c ${PROJECT_NAME}.cpp)
find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)
find_package(GLEW REQUIRED)
include_directories( ${OPENGL_INCLUDE_DIRS}  ${GLEW_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME}.elf ${OPENGL_LIBRARIES} glfw GL dl ${GLEW_LIBRARIES} )

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
