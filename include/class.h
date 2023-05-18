#ifndef __CLASS_H__
#define __CLASS_H__
#include <inttypes.h>
#include <stdlib.h>
#include "../include/constant_pool.h"
#include "./attribute.h"
#include "./method.h"
#include "./field.h"
typedef struct classfile
{
  uint32_t magic;
  uint16_t minor_version;
  uint16_t major_version;
  uint16_t constant_pool_count;
  cp_info *constant_pool;
  uint16_t access_flags;
  uint16_t this_class;
  uint16_t super_class;
  uint16_t interface_count;
  uint16_t *interfaces;
  uint16_t field_count;
  field_info* fileds;
  uint16_t method_count;
  method_info *methods;
  uint16_t attribute_count;
  attribute_info *attributes;
}classfile;

classfile read_classfile(const char* filename);
#endif
