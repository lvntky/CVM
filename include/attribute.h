#ifndef __ATTRIBUTE_H__
#define __ATTRIBUTE_H__
#include <stdint.h>
#include <stdio.h>

typedef struct attribute_info
{
  uint16_t attribute_name_index;
  uint32_t attribute_length;
  uint8_t *info;
}attribute_info;

// JVM SPEC REF: 4.7.5
// for exception throwing methods
typedef struct exception_table
{
  uint16_t attribute_name_index;
  uint32_t attribute_length;
  uint16_t number_of_exceptions;
  uint16_t *exception_index_table;
}exception_table;

// A Code attribute contains the Java Virtual Machine instructions and auxiliary
// information for a method, including an instance initialization method and a class or
// interface initialization method
typedef struct Code_attribute
{
    uint16_t attribute_name_index;
    uint32_t attribute_length;
    uint16_t max_stack;
    uint16_t max_locals;
    uint32_t code_length;
    uint8_t* code;
    uint16_t exception_table_lenght;
    exception_table* exceptionTable;
    uint16_t attributes_count;
    attribute_info* attributes;
} Code_attribute;

attribute_info parse_attribute_info(FILE* file);
Code_attribute get_code_attribute(attribute_info response);
#endif
