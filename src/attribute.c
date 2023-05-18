#include "../include/attribute.h"
#include "../include/bigendian.h"
#include <stdlib.h>
#include <string.h>

attribute_info parse_attribute_info(FILE* file)
{
  attribute_info attribute_info;
  fread(&attribute_info.attribute_name_index, sizeof(attribute_info.attribute_name_index), 1, file);
  attribute_info.attribute_name_index = be16toh(attribute_info.attribute_name_index);

  fread(&attribute_info.attribute_length, sizeof(attribute_info.attribute_length), 1, file);
  attribute_info.attribute_length = be32toh(attribute_info.attribute_length);

  attribute_info.info = malloc(attribute_info.attribute_length);
  fread(&attribute_info.info, attribute_info.attribute_length, 1, file);

  fclose(file);
  return attribute_info;
}
Code_attribute get_code_attribute(attribute_info attributeInfo)
{
  Code_attribute attribute;
  attribute.attribute_name_index = attributeInfo.attribute_name_index;
    attribute.attribute_length = attributeInfo.attribute_length;

    int memOffset=0;
    memcpy(&attribute.max_stack, attributeInfo.info+memOffset,sizeof(attribute.max_stack));
    attribute.max_stack = be16toh(attribute.max_stack);
    memOffset +=sizeof(attribute.max_stack);

    memcpy(&attribute.max_locals, attributeInfo.info+memOffset,sizeof(attribute.max_locals));
    attribute.max_locals = be16toh(attribute.max_locals);
    memOffset +=sizeof(attribute.max_locals);

    memcpy(&attribute.code_length, attributeInfo.info+memOffset,sizeof(attribute.code_length));
    attribute.code_length = be32toh(attribute.code_length);
    memOffset +=sizeof(attribute.code_length);

    attribute.code = attributeInfo.info+memOffset; // leak
    memOffset +=attribute.code_length;

    return attribute;
}
