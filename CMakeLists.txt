cmake_minimum_required(VERSION 3.24.0-rc4)

project(3d_editor)

file( GLOB_RECURSE SOURCES src/*.cpp src/*.hpp )

configure_file( cmake_defines.hpp.in ${CMAKE_SOURCE_DIR}/src/cmake_defines.hpp )

add_subdirectory("./ext/stb_image")

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_SOURCE_DIR}/cmake)
find_package(wxWidgets 3.2 COMPONENTS core base xrc gl adv REQUIRED)
find_package(GLEW REQUIRED)
find_package(OpenGL REQUIRED)
find_package(GLM REQUIRED)


include_directories(${CMAKE_SOURCE_DIR}/src)
include(${wxWidgets_USE_FILE})

add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} ${wxWidgets_LIBRARIES} ${GLEW_LIBRARIES} ${OPENGL_LIBRARIES} ${GLM_LIBRARIES} stb_image)

install (TARGETS ${PROJECT_NAME} RUNTIME DESTINATION bin)
