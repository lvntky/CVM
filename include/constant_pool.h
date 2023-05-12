#ifndef __CONSTANT_POOL_H__
#define __CONSTANT_POOL_H__

#include <inttypes.h>
#include <stdio.h>


typedef enum cp_tags{
    CONSTANT_Class=7,

    CONSTANT_Fieldref=9,

    CONSTANT_Methodref=10,

    CONSTANT_InterfaceMethodref=11,
    CONSTANT_String=8,

    CONSTANT_Integer=3,
    CONSTANT_Float=4,
    CONSTANT_Long=5,
    CONSTANT_Double=6,
    CONSTANT_NameAndType=12,

    CONSTANT_Utf8=1,

    CONSTANT_MethodHandle=15,
    CONSTANT_MethodType=16,
    CONSTANT_InvokeDynamic=18
}cp_tags;


typedef struct cp_info
{
  uint8_t tag;
  cp_tags tags;
}cp_info;

#endif
