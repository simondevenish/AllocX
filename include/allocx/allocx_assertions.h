#ifndef ALLOCX_ASSERTIONS_H
#define ALLOCX_ASSERTIONS_H

#ifdef __cplusplus
extern "C" {
#endif

#include <assert.h>
#include <stdio.h>

#define ALLOCX_ASSERT(condition, message) \
    do { \
        if (!(condition)) { \
            fprintf(stderr, "Assertion failed: %s\n", message); \
            assert(condition); \
        } \
    } while (0)

#ifdef __cplusplus
}
#endif

#endif // ALLOCX_ASSERTIONS_H
