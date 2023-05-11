#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <arpa/inet.h>

struct class_file_header {
    uint32_t magic;
    uint16_t minor_version;
    uint16_t major_version;
};

int read_class_file(const char *filename, uint8_t *buffer, size_t buffer_size) {
    FILE *file_ptr;
    size_t read_size;

    file_ptr = fopen(filename, "rb");
    if (file_ptr == NULL) {
        printf("Error: Failed to open file\n");
        return -1;
    }

    read_size = fread(buffer, sizeof(uint8_t), buffer_size, file_ptr);

    fclose(file_ptr);

    return (int)read_size;
}

int parse_class_file_header(const uint8_t *buffer, struct class_file_header *header) {
    header->magic = ntohl(*(uint32_t*)buffer);
    header->minor_version = ntohs(*(uint16_t*)(buffer + 4));
    header->major_version = ntohs(*(uint16_t*)(buffer + 6));

    return 0;
}

int main(int argc, char *argv[]) {
    uint8_t buffer[8];
    struct class_file_header header;

    if (argc != 2) {
        printf("Usage: %s <class file>\n", argv[0]);
        exit(1);
    }

    if (read_class_file(argv[1], buffer, sizeof(buffer)) < 0) {
        exit(1);
    }

    if (parse_class_file_header(buffer, &header) < 0) {
        printf("Error: Failed to parse class file header\n");
        exit(1);
    }

    printf("Magic: %X\n", header.magic);
    printf("Minor version: %d\n", header.minor_version);
    printf("Major version: %d\n", header.major_version);

    return 0;
}
