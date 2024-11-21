#ifndef ALLOCX_MEMORY_POOL_H
#define ALLOCX_MEMORY_POOL_H

#include "allocx_core_types.h"  // Core types like usize, u8, etc.
#include "allocx_atomic.h"      // Atomic utilities for thread safety
#include "allocx_errors.h"      // Error return codes

// Memory pool structure
typedef struct AllocXMemoryPool {
    mem_ptr_t memory_start;          // Start of the memory region
    mem_size_t block_size;           // Size of each block
    usize total_blocks;              // Total number of blocks in the pool
    u8* free_list;                   // Bitmap for free/allocated blocks
    atomic_size_t free_count;        // Number of free blocks (atomic for thread safety)
    atomic_size_t allocated_count;   // Number of allocated blocks
} AllocXMemoryPool;

/**
 * Initializes a memory pool with the specified block size and number of blocks.
 *
 * @param pool Pointer to the AllocXMemoryPool structure
 * @param block_size Size of each block
 * @param total_blocks Total number of blocks in the pool
 * @return ALLOCX_SUCCESS on success, or an appropriate error code from allocx_error_t on failure.
 */
allocx_error_t allocx_memory_pool_init(AllocXMemoryPool* pool, mem_size_t block_size, usize total_blocks);

/**
 * Allocates a block of memory from the pool.
 *
 * @param pool Pointer to the AllocXMemoryPool structure
 * @return Pointer to the allocated memory block, or NULL if no blocks are available
 */
mem_ptr_t allocx_memory_pool_alloc(AllocXMemoryPool* pool);

/**
 * Frees a block of memory back to the pool.
 *
 * @param pool Pointer to the AllocXMemoryPool structure
 * @param block Pointer to the memory block to free
 */
void allocx_memory_pool_free(AllocXMemoryPool* pool, mem_ptr_t block);

/**
 * Cleans up the memory pool and releases resources.
 *
 * @param pool Pointer to the AllocXMemoryPool structure
 */
void allocx_memory_pool_destroy(AllocXMemoryPool* pool);

#endif // ALLOCX_MEMORY_POOL_H