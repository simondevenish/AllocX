#ifndef ALLOCX_UTILITIES_H
#define ALLOCX_UTILITIES_H

#ifdef __cplusplus
extern "C" {
#endif

#include "allocx_alignment.h"

// Array size
#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))

// Range
#define IN_RANGE(value, min, max) ((value) >= (min) && (value) <= (max))
#define CLAMP(value, min, max) (allocx_min(allocx_max((value), (min)), (max)))

#ifdef __cplusplus
}
#endif

#endif // ALLOCX_UTILITIES_H