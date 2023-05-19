cmake_minimum_required(VERSION 3.26.3)
project(CVM)
add_executable(cvm ./src/class.c ./include/class.h ./src/constant_pool.c ./include/constant_pool.h ./src/attribute.c ./include/attribute.h ./src/field.h ./include/field.h)
