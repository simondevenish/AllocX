#ifndef ALLOCX_ERRORS_H
#define ALLOCX_ERRORS_H

typedef enum {
    ALLOCX_SUCCESS = 0,
    ALLOCX_ERROR_OUT_OF_MEMORY,
    ALLOCX_ERROR_INVALID_ARGUMENT,
    ALLOCX_ERROR_ALIGNMENT,
    ALLOCX_ERROR_OVERFLOW,
    ALLOCX_ERROR_UNKNOWN
} allocx_error_t;

#endif // ALLOCX_ERRORS_H