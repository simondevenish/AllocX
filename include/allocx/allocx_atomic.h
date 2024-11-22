#ifndef ALLOCX_ATOMIC_H
#define ALLOCX_ATOMIC_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdatomic.h>

// Memory order macros
#define ALLOCX_MEMORY_ORDER_RELAXED memory_order_relaxed
#define ALLOCX_MEMORY_ORDER_ACQUIRE memory_order_acquire
#define ALLOCX_MEMORY_ORDER_RELEASE memory_order_release
#define ALLOCX_MEMORY_ORDER_SEQ_CST memory_order_seq_cst

// Memory Barrier Macro
#define ALLOCX_MEMORY_BARRIER() __sync_synchronize()

// Atomic Operations
#define ALLOCX_ACQUIRE(ptr) __atomic_load_n(ptr, __ATOMIC_ACQUIRE)
#define ALLOCX_RELEASE(ptr, value) __atomic_store_n(ptr, value, __ATOMIC_RELEASE)
#define ALLOCX_RELAXED(ptr) __atomic_load_n(ptr, __ATOMIC_RELAXED)
#define ALLOCX_SEQ_CST(ptr, value) __atomic_store_n(ptr, value, __ATOMIC_SEQ_CST)
#define ALLOCX_ATOMIC_EXCHANGE(ptr, new_value) __atomic_exchange_n(ptr, new_value, __ATOMIC_SEQ_CST)
#define ALLOCX_CAS(ptr, expected, desired) __atomic_compare_exchange_n( \
    ptr, &expected, desired, false, __ATOMIC_SEQ_CST, __ATOMIC_SEQ_CST)

// Atomic Operations for Lock-Free
#define ALLOCX_FETCH_ADD(ptr, value) __atomic_fetch_add(ptr, value, __ATOMIC_SEQ_CST)
#define ALLOCX_FETCH_SUB(ptr, value) __atomic_fetch_sub(ptr, value, __ATOMIC_SEQ_CST)
#define ALLOCX_FETCH_AND(ptr, value) __atomic_fetch_and(ptr, value, __ATOMIC_SEQ_CST)
#define ALLOCX_FETCH_OR(ptr, value)  __atomic_fetch_or(ptr, value, __ATOMIC_SEQ_CST)

#ifdef __cplusplus
}
#endif

#endif // ALLOCX_ATOMIC_H
