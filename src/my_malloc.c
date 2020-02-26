/*
** EPITECH PROJECT, 2020
** my malloc
** File description:
** not as good as the original
*/

#include "my_free.h"
#include "my_malloc.h"
#include "macro.h"
#include "object.h"
#include "tools.h"
#include <unistd.h>

void *split(free_metadata_t ptr, size_t scaled_size)
{
    free_metadata_t potential_chunk = NULL;
    size_t size_offst = ptr->size - scaled_size;

    if ((size_offst) > (SIZE_METADATA + 16)) {
        ptr->size = scaled_size;
        potential_chunk = FREED_HEADER(NEXTHEADER(ptr));
        potential_chunk->free = 1;
        potential_chunk->size = size_offst;
        potential_chunk->next_free = NULL;
        potential_chunk->prev_free = NULL;
        potential_chunk->next = ptr->next;
        ptr->next = HEADER(potential_chunk);
        sprout_tree(potential_chunk);
    }
    return ptr;
}

void *malloc(size_t size)
{
    size_t scaled_size = SCALE_SIZE((size + SIZE_METADATA), 16);
    size_t total_size = TOTAL_PAGE_SIZE(scaled_size);
    void *ptr = NULL;

    if (tree.root)
        ptr = best_fitting_space(scaled_size);
    else {
        tree.root = sbrk(0);
        ptr = sbrk(total_size);
        if (ptr == ((void *)-1))
            return NULL;
        HEADER(ptr)->free = 0;
        HEADER(ptr)->size = scaled_size;
        HEADER(ptr)->next = NULL;
    }
    return (CHUNK(ptr));;
}