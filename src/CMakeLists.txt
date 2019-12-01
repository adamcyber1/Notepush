cmake_minimum_required(VERSION 3.10)
project(psh)

add_subdirectory(notepush)
set(SOURCE_FILES main.cpp)

add_executable(psh ${SOURCE_FILES})
target_link_libraries(psh notepush)
install(TARGETS psh DESTINATION ${NOTEPUSH_INSTALL_BIN_DIR})
