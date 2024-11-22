#ifndef ALLOCX_MEMORY_POOL_H
#define ALLOCX_MEMORY_POOL_H

#include "allocx_core_types.h"  // Core types like usize, u8, etc.
#include "allocx_atomic.h"      // Atomic utilities for thread safety
#include "allocx_errors.h"      // Error return codes

/**
 * AllocXMemoryPool:
 *
 * A memory pool that manages a fixed number of memory blocks. The memory pool enables
 * allocation and deallocation of blocks without the performance hit of repeatedly
 * requesting memory from the system.
 *
 * Key Fields:
 * - `memory_start`: A pointer to the start of the contiguous memory region managed by the pool.
 * - `block_size`: The size of each memory block in bytes.
 * - `total_blocks`: The total number of blocks in the pool.
 * - `free_list`: A bitmap that tracks the allocation status of each block in the pool.
 *   - Each bit in the `free_list` represents the status of a single block.
 *     - `0`: The block is free (available for allocation).
 *     - `1`: The block is allocated (in use).
 *   - For example - if the `free_list` is:
 *       byte:    0b11000101
 *       blocks:  [1][2][3][4][5][6][7][8]
 *       status:   A  F  A  F  F  F  A  A
 *     In this case:
 *       - Blocks 1, 3, 7, and 8 are allocated (bit = 1).
 *       - Blocks 2, 4, 5, and 6 are free (bit = 0).
 *   - The number of bytes required for the `free_list` is calculated as:
 *     `ceil(total_blocks / 8)` to account for one bit per block.
 * - `free_count`: An atomic counter representing the number of free blocks in the pool.
 * - `allocated_count`: An atomic counter representing the number of allocated blocks.
 *
 * Operations:
 * - ALLOCATION:
 *   - A block is allocated by finding the first `0` bit in the `free_list` and
 *     marking it as `1` (allocated) using a bitwise OR operation.
 *   - The `free_count` is decremented, and the `allocated_count` is incremented atomically.
 * - DEALLOCATION:
 *   - A block is freed by marking its corresponding bit in the `free_list` as `0`
 *   - The `free_count` is incremented, and the `allocated_count` is decremented atomically.
 */
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