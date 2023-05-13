#ifndef __BIGENDIAN_H__
#define __BIGENDIAN_H__

#define be8toh(x) __builtin_bswap8(x)
#define be16toh(x) __builtin_bswap16(x)
#define be32toh(x) __builtin_bswap32(x)
#define be64toh(x) __builtin_bswap64(x)

#endif
