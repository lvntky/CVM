#include "../include/class.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *get_bytecode(const char *filename)
{
  FILE *fileptr = fopen(filename, "rb");
  char *buffer = (char *)malloc(2 * sizeof(char));
  buffer[0] = '\0';
  unsigned char byte;
  while(fread(&byte, sizeof(byte), 1, fileptr) == 1) {
    char *temp = (char *) malloc(3 * sizeof(char));
    sprintf(temp, "%02x", byte);
    buffer = (char *) realloc(buffer, strlen(buffer) + strlen(temp) + 1);
    strcat(buffer, temp);
    free(temp);
  }
  fclose(fileptr);
  return buffer;
}
classfile read_class(char *bytecode, classfile class_elements)
{
  char *sub;
  int interval = 0;
  memcpy(class_elements.magic, bytecode, interval + 8);
  interval += 8;
  class_elements.magic[interval + 1] = '\0';
  return class_elements;
}

//driver
int main(int argc, char** argv)
{
  classfile class_elements;
  read_class(get_bytecode(argv[1]), class_elements);
  printf("%s", class_elements.magic);
  return 0;
}
