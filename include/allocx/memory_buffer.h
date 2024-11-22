#ifndef ALLOCX_BUFFER_H
#define ALLOCX_BUFFER_H

#ifdef __cplusplus
extern "C" {
#endif


#include "allocx_core_types.h"
#include "allocx_atomic.h"
#include "allocx_errors.h"

typedef struct AllocXBuffer
{
    mem_ptr_t memory_start; // Start of the buffer
    usize capacity;         // Total capacity of the buffer
    usize start;            // Read position
    usize end;              // Write position
} AllocXBuffer;

/**
 * Initialize a buffer with the specified capacity.
 * @param buf Pointer to AllocXBuffer
 * @param capacity Size of the buffer in bytes
 * @return ALLOCX_SUCCESS on success, or an appropriate error code
 */
allocx_error_t allocx_buffer_init(AllocXBuffer *buf, usize capacity);

/**
 * Free resources associated with the buffer.
 * @param buf Pointer to AllocXBuffer
 */
void allocx_buffer_destroy(AllocXBuffer *buf);

/**
 * Reset the buffer for reuse.
 * @param buf Pointer to AllocXBuffer
 */
void allocx_buffer_reset(AllocXBuffer *buf);

/**
 * Get the size of data currently in the buffer.
 * @param buf Pointer to AllocXBuffer
 * @return Size of data in bytes
 */
usize allocx_buffer_size(const AllocXBuffer *buf);

/**
 * Get the remaining space in the buffer.
 * @param buf Pointer to AllocXBuffer
 * @return Remaining space in bytes
 */
usize allocx_buffer_remaining(const AllocXBuffer *buf);

/**
 * Write a single byte to the buffer.
 * @param buf Pointer to AllocXBuffer
 * @param byte Byte to write
 */
void allocx_buffer_put(AllocXBuffer *buf, u8 byte);

/**
 * Peek at a single byte from the buffer without advancing the read pointer.
 * @param buf Pointer to AllocXBuffer
 * @return The byte at the current read position
 */
u8 allocx_buffer_peek(const AllocXBuffer *buf);

/**
 * Read a single byte from the buffer.
 * @param buf Pointer to AllocXBuffer
 * @return The byte read
 */
u8 allocx_buffer_get(AllocXBuffer *buf);

/**
 * Compact the buffer to make room for more data.
 * Moves remaining data to the start of the buffer.
 * @param buf Pointer to AllocXBuffer
 */
void allocx_buffer_compact(AllocXBuffer *buf);

/**
 * Append data from one buffer to another.
 * @param dst Destination buffer
 * @param src Source buffer
 * @return ALLOCX_SUCCESS on success, or an error code
 */
allocx_error_t allocx_buffer_append(AllocXBuffer *dst, const AllocXBuffer *src);

#ifdef __cplusplus
}
#endif

#endif // ALLOCX_BUFFER_H
