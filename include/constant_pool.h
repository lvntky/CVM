#ifndef __CONSTANT_POOL_H__
#define __CONSTANT_POOL_H__

#include <inttypes.h>
#include <stdio.h>

// Tag Identifier
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

/* constants START */
typedef struct CONSTANT_Class_Info
{
  uint16_t name_index;
}CONSTANT_Class_Info;

typedef struct CONSTANT_Ref_Info
{
  uint16_t class_index;
  uint16_t name_and_type_index;
}CONSTANT_Ref_Info;

typedef struct CONSTANT_String_Info
{
  uint16_t string_index;
}CONSTANT_String_Info;

typedef struct CONSTANT_4BYTES_Info
{
  uint32_t bytes;
}CONSTANT_4BYTES_Info;

typedef struct CONSTANT_8BYTES_Info
{
  uint64_t bytes;
}CONSTANT_8BYTES_Info;

typedef struct CONSTANT_NameAndType_Info
{
  uint16_t name_index;
  uint16_t descriptor_index;
}CONSTANT_NameAndType_Info;

typedef struct CONSTANT_Utf8_Info
{
  uint16_t length;
  uint8_t* bytes;
}CONSTANT_Utf8_Info;

typedef struct CONSTANT_MethodHandle_Info
{
  uint8_t reference_kind;
  uint16_t reference_index;
}CONSTANT_MethodHandle_Info;

typedef struct CONSTANT_MethodType_Info
{
  uint16_t descriptor_index;
}CONSTANT_MethodType_Info;

typedef struct CONSTANT_InvokeDynamic_Info
{
  uint16_t boostrap;
  uint16_t name_and_type_index;
}CONSTANT_InvokeDynamic_Info;

typedef enum primitive_types_array
  {
    T_BOOLEAN = 4,
    T_CHAR = 5,
    T_FLOAT = 6,
    T_BYTE = 8,
    T_SHORT = 9,
    T_INT = 10,
    T_LONG = 11
  }primitive_types_array;

//primitive types
typedef struct CONSTANT_Array_Info
{
  int32_t size;
  primitive_types_array ptarray;
  uint8_t* ref;
}CONSTANT_Array_Info;
/* constants END */

// constant pool
typedef struct constant_info
{
  CONSTANT_Class_Info class_info;
  CONSTANT_Ref_Info ref_info;
  CONSTANT_String_Info string_info;
  CONSTANT_4BYTES_Info _4BYTES_info;
  CONSTANT_8BYTES_Info _8BYTES_info;
  CONSTANT_NameAndType_Info nameAndType_info;
  CONSTANT_Utf8_Info utf8_info;
  CONSTANT_MethodHandle_Info methodHandle_info;
  CONSTANT_MethodType_Info methodType_info;
  CONSTANT_InvokeDynamic_Info invokeDynamic_info;
}constant_info;

// Meta-Information of constant pool
typedef struct cp_info
{
  uint8_t tag;
  constant_info info;
}cp_info;

cp_info parse_constant_pool(const char* file_dest);
void free_constant_pool(constant_info constant_info);
#endif
