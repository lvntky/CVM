cmake_minimum_required(VERSION 3.26.3)
project(CVM)
add_compile_options(-fno-stack-protector)
add_executable(cvm ./src/class.c ./include/class.h ./src/constant_pool.c ./include/constant_pool.h ./src/attribute.c ./include/attribute.h ./src/field.c ./include/field.h)
