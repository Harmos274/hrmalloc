/*
** EPITECH PROJECT, 2020
** my malloc
** File description:
** azeerty
*/

#ifndef MY_MALLOC_H_
#define MY_MALLOC_H_

#include "object.h"
#include "macro.h"

// Function prototypes

#ifndef _MALLOC_GLOBAL
    #define _MALLOC_GLOBAL
    struct tree_s tree = {NULL, {0, NULL}, {0, NULL}, {0, NULL}, {0, NULL}};
#else
    extern struct tree_s tree;
#endif /*_MALLOC_GLOBAL*/


void *malloc(size_t size);
void free(void *ptr);
void *calloc(size_t nmemb, size_t size);
void *realloc(void *ptr, size_t size);
void *reallocarray(void *ptr, size_t nmemb, size_t size);

#endif
