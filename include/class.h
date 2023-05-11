#ifndef __CLASS_H
#define __CLASS_H
#include <stdint.h>
typedef struct
{
  char* magic;
}classfile;

char *get_bytecode(const char* filename);
classfile read_class(char *bytecode, classfile class_elements);
#endif
