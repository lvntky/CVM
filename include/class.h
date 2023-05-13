#ifndef __CLASS_H__
#define __CLASS_H__
#include <inttypes.h>
#include <stdlib.h>
#include "../include/constant_pool.h"

typedef struct classfile
{
  uint32_t magic;
  uint16_t minor_version;
  uint16_t major_version;
  uint16_t constant_pool_count;
  constant_pool *constant_pool;
}classfile;

classfile read_classfile(const char* filename);
#endif
