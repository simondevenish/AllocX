#ifndef ALLOCX_ALIGNMENT_H
#define ALLOCX_ALIGNMENT_H

#include "allocx_core_types.h"

// Alignment macros
#define ALIGN_UP(value, alignment) (((value) + ((alignment)-1)) & ~((alignment)-1))
#define ALIGN_DOWN(value, alignment) ((value) & ~((alignment)-1))
#define IS_ALIGNED(value, alignment) (((value) & ((alignment)-1)) == 0)

// Alignment types
typedef u8 align8_t __attribute__((aligned(8)));
typedef u16 align16_t __attribute__((aligned(16)));
typedef u32 align32_t __attribute__((aligned(32)));
typedef u64 align64_t __attribute__((aligned(64)));

#endif // ALLOCX_ALIGNMENT_H
