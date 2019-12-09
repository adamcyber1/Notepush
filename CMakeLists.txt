cmake_minimum_required(VERSION 3.11)
cmake_policy(VERSION 3.11)

project(Notepush)

if (NOT (UNIX))
  message(FATAL_ERROR "unsupported target platform...windows isn't supported yet")
endif()

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

# languages
enable_language(CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1z -O0 -Wall")

# options
option(BUILD_SHARED_LIBS "Build shared library" ON)
option(BUILD_TESTS "Build Tests" OFF)


if(BUILD_SHARED_LIBS)
    message("BUILD_SHARED_LIBS: ON")
else()
    message("BUILD_SHARED_LIBS: OFF")
endif()

if(BUILD_TESTS)
    enable_testing()
    message("BUILD_TESTS: ON")
else()
    message("BUILD_TESTS: OFF")
endif()

set(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR})

set(NOTEPUSH_INSTALL_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/build/include)
set(NOTEPUSH_INSTALL_BIN_DIR ${PROJECT_SOURCE_DIR}/build/bin)
set(NOTEPUSH_INSTALL_LIB_DIR ${PROJECT_SOURCE_DIR}/lib)

set(NOTEPUSH_HEADERS_DIR ${PROJECT_SOURCE_DIR}/src/notepush)

include_directories(${NOTEPUSH_INSTALL_INCLUDE_DIR})
include_directories(${NOTEPUSH_HEADERS_DIR})
include_directories(${PROJECT_SOURCE_DIR}/src)

find_package(Gtest REQUIRED)
find_package(Git2 REQUIRED)

add_subdirectory(src)

if(BUILD_TESTS)
  add_subdirectory(tests)
endif()