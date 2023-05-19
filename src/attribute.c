#include "../include/attribute.h"
#include "../include/bigendian.h"
#include <stdlib.h>
#include <string.h>

attribute_info parse_attribute_info(FILE* fd)
{
  attribute_info attribute;
    fread(&attribute.attribute_name_index,sizeof(attribute.attribute_name_index),1,fd);
    attribute.attribute_name_index = be16toh(attribute.attribute_name_index);

    fread(&attribute.attribute_length,sizeof(attribute.attribute_length),1,fd);
    attribute.attribute_length = be32toh(attribute.attribute_length);

    attribute.info = malloc(attribute.attribute_length); // leak
    fread(attribute.info,attribute.attribute_length,1,fd);
    return attribute;
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
