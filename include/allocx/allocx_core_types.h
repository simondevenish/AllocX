#ifndef ALLOCX_CORE_TYPES_H
#define ALLOCX_CORE_TYPES_H

#ifdef __cplusplus
extern "C" {
#endif


#include <stddef.h>
#include <stdint.h>

// Unsigned size type
typedef size_t usize;

// Signed size type
typedef ptrdiff_t isize;

// 8-bit types
typedef uint8_t u8;
typedef int8_t i8;

// 16-bit types
typedef uint16_t u16;
typedef int16_t i16;

// 32-bit types
typedef uint32_t u32;
typedef int32_t i32;

// 64-bit types
typedef uint64_t u64;
typedef int64_t i64;

// Specialised pointers
typedef void* mem_ptr_t;   // Generic memory pointer
typedef usize mem_size_t;  // Memory size in bytes
typedef isize mem_offset_t; // Memory offset

#ifdef __cplusplus
}
#endif

#endif // ALLOCX_CORE_TYPES_H
