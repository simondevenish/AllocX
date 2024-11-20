#ifndef ALLOCX_BITWISE_UTILS_H
#define ALLOCX_BITWISE_UTILS_H

#include "allocx_core_types.h"

// Get the Nth bit of a value
#define ALLOCX_BIT(n) (1U << (n))

// Check if the Nth bit is set
#define ALLOCX_IS_BIT_SET(value, n) (((value) & ALLOCX_BIT(n)) != 0)

// Set the Nth bit
#define ALLOCX_SET_BIT(value, n) ((value) |= ALLOCX_BIT(n))

// Clear the Nth bit
#define ALLOCX_CLEAR_BIT(value, n) ((value) &= ~ALLOCX_BIT(n))

// Toggle the Nth bit
#define ALLOCX_TOGGLE_BIT(value, n) ((value) ^= ALLOCX_BIT(n))

// Generate a mask with the first N bits set
#define ALLOCX_MASK(n) ((1U << (n)) - 1)

// Extract a bitfield
#define ALLOCX_EXTRACT_FIELD(value, shift, mask) (((value) >> (shift)) & (mask))

// Insert a value into a bitfield
#define ALLOCX_INSERT_FIELD(value, field, shift, mask) \
    (((value) & ~((mask) << (shift))) | (((field) & (mask)) << (shift)))

// Check if a value is a power of two
#define ALLOCX_IS_POWER_OF_TWO(value) ((value) && !((value) & ((value)-1)))

// Round up to the nearest power of two
#define ALLOCX_ROUND_UP_POWER_OF_TWO(value) \
    (1ULL << (64 - __builtin_clzll((value)-1)))

// Round down to the nearest power of two
#define ALLOCX_ROUND_DOWN_POWER_OF_TWO(value) \
    (1ULL << (__builtin_clzll(value) - (ALLOCX_IS_POWER_OF_TWO(value) ? 0 : 1)))

// Count the number of set bits (population count)
#define ALLOCX_COUNT_BITS(value) __builtin_popcountll(value)

// Find the position of the highest set bit (zero-based)
#define ALLOCX_HIGHEST_BIT_POSITION(value) (63 - __builtin_clzll(value))

// Find the position of the lowest set bit (zero-based)
#define ALLOCX_LOWEST_BIT_POSITION(value) (__builtin_ctzll(value))

#endif // ALLOCX_BITWISE_UTILS_H
