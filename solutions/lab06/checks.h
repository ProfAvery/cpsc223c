#ifndef CHECKS_H
#define CHECKS_H

#include <stdbool.h>
#include <stdlib.h>

#ifdef BSTR_OK

#define CHECK_BSTR_OK(expr) do { \
    if ((expr) != BSTR_OK) { \
        fprintf(stderr, "%s:%d: (%s) != BSTR_OK\n", __FILE__, __LINE__, #expr); \
        exit(EXIT_FAILURE); \
    } \
} while (false)

#endif

#define CHECK_NOT_NULL(expr) do { \
    if ((expr) == NULL) { \
        fprintf(stderr, "%s:%d: (%s) == NULL\n", __FILE__, __LINE__, #expr); \
        exit(EXIT_FAILURE); \
    } \
} while (false)

#endif

