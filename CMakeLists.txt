cmake_minimum_required(VERSION 3.15)
project(cvm CXX)




add_library(cvm src/cvm.cpp)
target_include_directories(cvm PUBLIC include)



set_target_properties(cvm PROPERTIES PUBLIC_HEADER "include/cvm.h")
install(TARGETS cvm)
