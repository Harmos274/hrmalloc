/*
** EPITECH PROJECT, 2020
** my_malloc
** File description:
** auxiliary functions
*/

#define _MALLOC_GLOBAL
#include "my_malloc.h"
#include "macro.h"
#include "tree_managing.h"
#include <limits.h>
#include <string.h>

void *calloc(size_t nmemb, size_t size)
{
    void *ptr = NULL;

    if ((nmemb > 0) && (size > 0) && ((nmemb * size) <= INT_MAX)) {
        ptr = malloc(nmemb * size);
        if (ptr)
            memset(ptr, 0, HEADER(START(ptr))->size - SIZE_METADATA);
    }
    return ptr;
}

void *realloc(void *ptr, size_t size)
{
    void *ret_ptr = NULL;

    if (!ptr) {
        return malloc(size);
    }
    if (HEADER(START(ptr))->size > SCALE_SIZE((size + SIZE_METADATA), 16)
        || size < HEADER(START(ptr))->size) {
            ret_ptr = ptr;
    } else {
        ret_ptr = malloc(size);
        if (ret_ptr) {
            memcpy(ret_ptr, ptr, HEADER(START(ptr))->size);
        }
        free(ptr);
    }
    return ret_ptr;
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
    if ((nmemb * size) > ULONG_MAX)
        return NULL;
    realloc(ptr, nmemb * size);
    return ptr;
}
