#ifndef __CLASS_H__
#define __CLASS_H__
#include <inttypes.h>
typedef struct classfile
{
  uint32_t magic;
  uint16_t minor_version;
  uint16_t major_version;
}classfile;

classfile read_classfile(const char* filename);
#endif
