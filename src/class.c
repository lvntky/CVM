#include "../include/bigendian.h"
#include "../include/class.h"
#include <stdio.h>
#include <stdlib.h>

classfile read_classfile(const char* filename)
{
  classfile classfile;
  FILE *fileptr;
  fileptr = fopen(filename, "rb");
  fread(&classfile.magic, sizeof(classfile.magic), 1, fileptr);
  classfile.magic = be32toh(classfile.magic);
  printf("MAGIC: %X\n", classfile.magic);
  fread(&classfile.minor_version, sizeof(classfile.minor_version), 1, fileptr);
  classfile.minor_version = be16toh(classfile.minor_version);
  printf("MINOR: %x\n", classfile.minor_version);
  fread(&classfile.major_version, sizeof(classfile.major_version), 1, fileptr);
  classfile.major_version = be16toh(classfile.major_version);
  printf("MAJOR: %x", classfile.major_version);
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
