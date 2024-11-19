#ifndef ALLOCX_ASSERTIONS_H
#define ALLOCX_ASSERTIONS_H

#include <assert.h>
#include <stdio.h>

#define ALLOCX_ASSERT(condition, message) \
    do { \
        if (!(condition)) { \
            fprintf(stderr, "Assertion failed: %s\n", message); \
            assert(condition); \
        } \
    } while (0)

#endif // ALLOCX_ASSERTIONS_H
