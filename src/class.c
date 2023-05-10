#include "../include/class.h"
#include <stdio.h>
#include <stdlib.h>

char *get_bytecode(const char *filename)
{
  FILE *fileptr = fopen(filename, "rb");
  char *buffer = (char *)malloc(2 * sizeof(char));



  return buffer;
}

int main(int argc, char** argv)
{
  get_bytecode(argv[1]);
  return 0;
}
