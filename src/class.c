#include "../include/class.h"
#include "../include/constant_pool.h"
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
  printf("(+) [CLASS INFO END]\n");
  classfile.constant_pool = malloc(sizeof(cp_info) * (classfile.constant_pool_count - 1));
  printf("\n=============================================\n");
  printf("\n(-) [CONST POOL INFO START]\n");
  for (int i = 0; i < classfile.constant_pool_count - 1; i++) {
    classfile.constant_pool[i] = parse_constant_pool(fileptr);
    printf("\t%d: constant:\t%d\n", i, classfile.constant_pool[i].tag);
  }
  printf("(+) [CONST POOL INFO END]\n");
  printf("\n=============================================\n");

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
