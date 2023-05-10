#include "../include/class_loader.h"
#include <stdlib.h>

// driver
int main (int argc, char** argv)
{
  FILE *fileptr = fopen(argv[1], "r");
  fseek(fileptr, 0, SEEK_END);
  long file_size = ftell(fileptr);
  rewind(fileptr);
  char *buffer = (char *)malloc(file_size * sizeof(char));
  fread(buffer, file_size, 1, fileptr);
  printf("%s",buffer);
  fclose(fileptr);
  return 0;
}
