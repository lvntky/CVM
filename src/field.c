#include "../include/field.h"
#include "../include/bigendian.h"
#include "../include/constant_pool.h"
#include <stdlib.h>
#include <stdio.h>

field_info parse_filed_info(FILE* fd){
    field_info field;
    fread(&field.access_flags,sizeof(field.access_flags),1,fd);
    field.access_flags = be16toh(field.access_flags);

    fread(&field.name_index,sizeof(field.name_index),1,fd);
    field.name_index = be16toh(field.name_index);

    fread(&field.descriptor_index,sizeof(field.descriptor_index),1,fd);
    field.descriptor_index = be16toh(field.descriptor_index);

    fread(&field.attributes_count,sizeof(field.attributes_count),1,fd);
    field.attributes_count = be16toh(field.attributes_count);

    field.attributes = malloc (sizeof(attribute_info) * field.attributes_count);
    for (int attributeCount=0; attributeCount<field.attributes_count; attributeCount++){
        field.attributes[attributeCount] = parse_attribute_info(fd); // leak
    }
    field.value = 0;
    return field;

}
