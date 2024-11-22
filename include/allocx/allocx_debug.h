#ifndef ALLOCX_DEBUG_H
#define ALLOCX_DEBUG_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>

// Debug Logging
#ifdef ALLOCX_DEBUG
    #define ALLOCX_LOG(fmt, ...) fprintf(stderr, "[ALLOCX] " fmt "\n", ##__VA_ARGS__)
#else
    #define ALLOCX_LOG(fmt, ...)
#endif

// Memory Dump
#define ALLOCX_DUMP_MEMORY(ptr, size) \
    do { \
        fprintf(stderr, "[ALLOCX] Memory Dump (size=%zu):\n", size); \
        for (usize i = 0; i < (size); ++i) { \
            fprintf(stderr, "%02x ", ((unsigned char*)(ptr))[i]); \
            if ((i + 1) % 16 == 0) fprintf(stderr, "\n"); \
        } \
        fprintf(stderr, "\n"); \
    } while (0)

#ifdef __cplusplus
}
#endif

#endif // ALLOCX_DEBUG_H
