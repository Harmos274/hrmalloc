/*
** EPITECH PROJECT, 2020
** my free
** File description:
** not as good as the original
*/

#include "object.h"
#include "tools.h"
#include "macro.h"
#include <unistd.h>
#include <signal.h>

void emplace_branch(bough_t *corresp, free_metadata_t discover,
    free_metadata_t chunk)
{
    if (discover->next_free) {
        while (discover->next_free && (discover->size <= chunk->size))
            discover = discover->next_free;
    }
    if (discover->size >= chunk->size) {
        if (discover->prev_free)
            discover->prev_free->next_free = chunk;
        else
            corresp->tree = chunk;
        chunk->prev_free = discover->prev_free;
        chunk->next_free = discover;
        discover->prev_free = chunk;
    } else {
        chunk->next_free = NULL;
        discover->next_free = chunk;
        chunk->prev_free = discover;
        corresp->max_size = chunk->size;
    }
}

void sprout_tree(free_metadata_t chunk)
{
    bough_t *corresp = get_coresp_branch(chunk->size, NOID);
    free_metadata_t discover = corresp->tree;

    if (!discover) {
        chunk->next_free = NULL;
        chunk->prev_free = NULL;
        corresp->tree = chunk;
        corresp->max_size = chunk->size;
    } else
        emplace_branch(corresp, discover, chunk);
}

void write_double_free(void)
{
    write(2, ERR_DOUBLE_FREE, sizeof(ERR_DOUBLE_FREE));
}

void free(void *ptr)
{
    if (ptr) {
        if (HEADER(START(ptr))->free == 1) {
            write_double_free();
            kill(0, SIGABRT);
        }
        HEADER(START(ptr))->free = 1;
        sprout_tree(FREED_HEADER(START(ptr)));
    }
}