/*
** EPITECH PROJECT, 2020
** my malloc
** File description:
** object
*/

#ifndef OBJECT_H_
#define OBJECT_H_

#include <stddef.h>

typedef struct metadata_s *metadata_t;
struct metadata_s
{
    int free;
    size_t size;
    metadata_t next;
};

typedef struct free_metadata_s *free_metadata_t;
struct free_metadata_s
{
    int free;
    size_t size;
    metadata_t next;
    free_metadata_t next_free;
    free_metadata_t prev_free;
};

typedef struct bough_s bough_t;
struct bough_s
{
    size_t max_size;
    free_metadata_t tree;
};

struct tree_s
{
    void *root;
    bough_t tiny_branch;
    bough_t medium_branch;
    bough_t large_branch;
    bough_t gigantic_branch;
};

// offset enum for cursor positioning

enum offset
{
    SIZE_METADATA = sizeof(struct metadata_s),
    SIZE_HEADER = sizeof(struct metadata_s)
};

// size limit

enum boundary
{
    TINY_BOUND = 4194304,
    MEDIUM_BOUND = 268435456,
    LARGE_BOUND = 2147483648,
    GIGANTIC_BOUND = (size_t)(-1)
};

// allocation type

typedef enum alloc_type alloc_type_t;
enum alloc_type
{
    NOID = -1,
    TINY = 0,
    MEDIUM = 1,
    LARGE = 2,
    GIGANTIC = 3
};

#endif
