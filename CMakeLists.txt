CMAKE_MINIMUM_REQUIRED(VERSION 3.0)
PROJECT(Named_pipe_ex CXX)
include(CTest)
include(CMakeDependentOption)

FIND_PACKAGE(Threads)
# enabling testing and setting up google test framework
# downloaded automatically at first build once.
ENABLE_TESTING()
CONFIGURE_FILE(cmake/googletestconfig.txt.in external/googletest/CMakeLists.txt)
EXECUTE_PROCESS(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
RESULT_VARIABLE result
WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/external/googletest )
if(result)
MESSAGE(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()

EXECUTE_PROCESS(COMMAND ${CMAKE_COMMAND} --build .
RESULT_VARIABLE result
WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/external/googletest )
if(result)
MESSAGE(FATAL_ERROR "Build step for googletest failed: ${result}")
endif()

# Prevent overriding the parent project's compiler/linker
# settings on Windows
SET(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This defines
# the gtest and gtest_main targets.
ADD_SUBDIRECTORY(${CMAKE_BINARY_DIR}/external/googletest/source
                ${CMAKE_BINARY_DIR}/external/googletest/build
                EXCLUDE_FROM_ALL)
include_directories(${CMAKE_BINARY_DIR}/external/googletest/source/googletest/include)
add_executable(all_tests tests/All_Tests.cpp)
target_link_libraries(all_tests gtest ${CMAKE_THREAD_LIBS_INIT})
add_test(NAME all_tests COMMAND ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/all_tests)
SET_PROPERTY(TARGET all_tests PROPERTY FOLDER "tests")

