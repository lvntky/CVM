#ifndef __CLASS_H
#define __CLASS_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
typedef struct
{
  uint32_t magic;
  uint16_t minor;
  uint16_t major;

}classfile;

char *get_bytecode(const char* filename);
classfile parse_class(const char *bytecode);
#endif
