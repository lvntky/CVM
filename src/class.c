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


  return buffer;
}
