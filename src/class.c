#include "../include/class.h"
#include "../include/constant_pool.h"
#include "../include/method.h"
#include <stdio.h>
#include <stdlib.h>

classfile read_classfile(const char* filename)
{
  classfile classfile;
  FILE *fileptr;
  fileptr = fopen(filename, "rb");
  printf("(-) [CLASS INFO START]\n");
  fread(&classfile.magic, sizeof(classfile.magic), 1, fileptr);
  classfile.magic = be32toh(classfile.magic);
  printf("\tMAGIC: %X\n", classfile.magic);

  fread(&classfile.minor_version, sizeof(classfile.minor_version), 1, fileptr);
  classfile.minor_version = be16toh(classfile.minor_version);
  printf("\tMINOR: %d\n", classfile.minor_version);

  fread(&classfile.major_version, sizeof(classfile.major_version), 1, fileptr);
  classfile.major_version = be16toh(classfile.major_version);
  printf("\tMAJOR: %d\n", classfile.major_version);

  fread(&classfile.constant_pool_count, sizeof(classfile.constant_pool_count), 1, fileptr);
  classfile.constant_pool_count = be16toh(classfile.constant_pool_count);
  printf("\tCONSTANT POOL COUNT: %d\n", classfile.constant_pool_count - 1);

  classfile.constant_pool = malloc(sizeof(cp_info) * (classfile.constant_pool_count - 1));
  printf("\n=============================================\n");
  printf("\n\t(-) [CONST POOL INFO START]\n");
  for (int i = 0; i < classfile.constant_pool_count - 1; i++) {
    classfile.constant_pool[i] = parse_constant_pool(fileptr);
    printf("\t\t%d: constant:\t%d\n", i, classfile.constant_pool[i].tag);
  }
  printf("\t(+) [CONST POOL INFO END]\n");
  printf("\n=============================================\n");
  fread(&classfile.access_flags, sizeof(classfile.access_flags), 1, fileptr);
  classfile.access_flags = be16toh(classfile.access_flags);
  printf("\n\tACCESS FLAGS:\t%d\n", classfile.access_flags);
  fread(&classfile.this_class, sizeof(classfile.this_class), 1, fileptr);
  classfile.this_class = be16toh(classfile.this_class);
  printf("\tTHIS CLASS:\t%d\n", classfile.this_class);
  fread(&classfile.super_class, sizeof(classfile.super_class), 1, fileptr);
  classfile.super_class = be16toh(classfile.super_class);
  printf("\tSUPER CLASS:\t%d\n", classfile.super_class);
  fread(&classfile.interface_count, sizeof(classfile.interface_count), 1, fileptr);
  printf("\tINTERFACE COUNT:\t%d\n", classfile.interface_count );

  printf("\n=============================================\n");
  printf("\n\t(-) [INTERFACE INFO START]\n");
  classfile.interfaces = malloc(classfile.interface_count * sizeof(uint16_t));
  if(classfile.interface_count < 1) {
    printf("\t\t***\tNo interface provided in bytecode\t***");
  } else {
    for(int j = 0; j < classfile.interface_count; j++){
      uint16_t interface;
      fread(&interface, sizeof(interface), 1, fileptr);
      classfile.interfaces[j] = be16toh(interface);
      printf("\t\t%d: interface:\t%d\n", j, classfile.interfaces[j]);
    }
  }
  printf("\n\t(+) [INTERFACE INFO END]\n");

  fread(&classfile.field_count, sizeof(classfile.field_count), 1, fileptr);
  classfile.field_count = be16toh(classfile.field_count);
  printf("\tFIELD COUNT:\t%d\n", classfile.field_count);
  // TODO: fileds
  fread(&classfile.method_count, sizeof(classfile.method_count), 1, fileptr);
  classfile.method_count = be16toh(classfile.method_count);
  printf("\tMETHOD COUNT:\t%d\n", classfile.method_count);
  classfile.methods = malloc(sizeof(method_info) * classfile.method_count);
  for (int method_counter = 0; method_counter < classfile.method_count; method_counter++) {
    classfile.methods[method_counter] = getMethod_Info(fileptr);
  }
  printf("(+) [CLASS INFO END]\n");
  //TODO
  fclose(fileptr);
  return classfile;
}


//driver
// TODO: DELETE
int main(int argc, char** argv)
{
  read_classfile(argv[1]);
  return 0;
}
