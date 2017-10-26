cmake_minimum_required(VERSION 3.5)

project(OpenGL_Playground)

# VIM YouCompleteMe setup
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
if( EXISTS "${CMAKE_CURRENT_BINARY_DIR}/compile_commands.json" )
  EXECUTE_PROCESS( COMMAND ${CMAKE_COMMAND} -E copy_if_different
    ${CMAKE_CURRENT_BINARY_DIR}/compile_commands.json
    ${CMAKE_CURRENT_SOURCE_DIR}/compile_commands.json
  )
endif()
# END VIM SETUP


set(library_SOURCES src/opengl_playground.cpp src/glad.c)
set(CMAKE_CXX_FLAGS "-std=c++17 -g -Wall")


find_package(OpenGL REQUIRED)

if(OPENGL_FOUND)
    message("Library for OpenGL Found on system.")
    add_library(Playgroundlib SHARED ${library_SOURCES})
    target_include_directories(Playgroundlib  PUBLIC 
        ${PROJECT_SOURCE_DIR}/include 
        ${PROJECT_SOURCE_DIR}/include/glad/
        ${PROJECT_SOURCE_DIR}/include/KHR/
    )
    include_directories(${OPENGL_INCLUDE_DIR})
    set(GL_DEPS GL X11 pthread Xrandr Xi)

    target_link_libraries(Playgroundlib glfw ${GL_DEPS} ${OPENGL_gl_LIBRARY})
    add_executable(Playground src/main.cpp)
    target_link_libraries(Playground Playgroundlib)     
    set(BUILT_EXECUTABLE TRUE)

elseif(NOT ${OPENGL_FOUND})
    # TODO: Try looking in lib for glfw
    # NOTE: I'm pretty sure this will actually never get reached.
    message("Error: Could not find external library for compiling opengl dependencies.")
endif()


option(test "Build all tests" OFF)
if(test AND ${BUILT_EXECUTABLE})
    find_package(GTest)
    if(GTEST_FOUND)
        include_directories(${GTEST_INCLUDE_DIRS})
        message("GTest libary found")
    else()
        message("Error: GTest Libraries not found")
        add_subdirectory(lib/googletest/googletest)
        set(GTEST_ROOT ${gtest_SOURCE_DIR})
        find_package(GTest REQUIRED)
        include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
    endif()

    enable_testing()
    set(test_SOURCES tests/test_simple.cpp)

    add_executable(Playground_UNIT_TESTS ${test_SOURCES})
    target_link_libraries(Playground_UNIT_TESTS gtest gtest_main Playgroundlib)
    add_test(NAME all_tests COMMAND Playground_UNIT_TESTS)
    message("All tests compiled")
endif()
