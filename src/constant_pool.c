#include "../include/constant_pool.h"
#include "../include/bigendian.h"
#include <stdio.h>
#include <stdlib.h>

cp_info parse_constant_pool(const char* buffer)
{
  cp_info info;
  buffer = "../test/Add.class"; // DEBUG
  FILE* fileptr = fopen(buffer, "rb");

  fread(&info.tag, 1, 1, fileptr); // size = 1 byte;
  printf("==================== CONST POOL INFO START ====================\n");\
  printf("CONSTANT: ");
  switch(info.tag) {


    case CONSTANT_Class:
    fread(&info.info.class_info.name_index, sizeof(info.info.class_info.name_index), 1, fileptr);
    info.info.class_info.name_index = be16toh(info.info.class_info.name_index);
    printf("CLASS\n");
    break;
  case CONSTANT_Fieldref:
  case CONSTANT_Methodref:
  case CONSTANT_InterfaceMethodref:
    fread(&info.info.ref_info.class_index, sizeof(info.info.ref_info.class_index), 1, fileptr);
    fread(&info.info.ref_info.name_and_type_index, sizeof(info.info.ref_info.name_and_type_index), 1, fileptr);
    info.info.ref_info.class_index = be16toh(info.info.ref_info.class_index);
    info.info.ref_info.name_and_type_index = be16toh(info.info.ref_info.name_and_type_index);
    printf("REF INFO\n");
    break;
    //TODO

  case CONSTANT_String:
    fread(&info.info.string_info.string_index, sizeof(info.info.string_info.string_index), 1, fileptr);
    info.info.string_info.string_index = be16toh(info.info.string_info.string_index);
    printf("STRING\n");
    break;
  default:
    printf("UNKNOWN CONSTANT... %d\n", info.tag);
    break;
  }

  fclose(fileptr);
  return info;
}

//DEMO DRIVER
int main(int argc, char** argv)
{
  parse_constant_pool(argv[1]);
  return 0;
}
