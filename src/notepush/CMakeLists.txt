cmake_minimum_required(VERSION 3.10)
project(notepush CXX)

set(SOURCE_FILES
    notepush.h
    notepush.cpp
)

add_library(notepush ${SOURCE_FILES})

target_link_libraries(notepush PUBLIC libgit2)

install(TARGETS notepush DESTINATION ${NOTEPUSH_INSTALL_LIB_DIR})
install(FILES notepush.h DESTINATION ${NOTEPUSH_INSTALL_INCLUDE_DIR})
