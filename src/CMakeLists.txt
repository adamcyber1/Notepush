cmake_minimum_required(VERSION 3.10)
project(psh)

find_package(Git2 REQUIRED)
find_package(Gtest REQUIRED)

add_subdirectory(notepush)
set(SOURCE_FILES main.cpp main.h)

add_executable(psh ${SOURCE_FILES})
target_link_libraries(psh notepush Git2::Git2)
install(TARGETS psh DESTINATION ${NOTEPUSH_INSTALL_BIN_DIR})