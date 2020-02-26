/*
** EPITECH PROJECT, 2020
** my_malloc
** File description:
** prune trees
*/

#define _MALLOC_GLOBAL
#include "macro.h"
#include "tools.h"
#include "prune_tree.h"

void repair_branch(bough_t *current, free_metadata_t discover)
{
    if (current->tree != discover) {
        discover->prev_free->next_free = discover->next_free;
        if (discover->next_free)
            discover->next_free->prev_free = discover->prev_free;
    } else {
        if (discover->next_free)
            discover->next_free->prev_free = NULL;
        current->tree = discover->next_free;
    }
}

void *prune_tree(size_t scaled_size, alloc_type_t tree_size)
{
    bough_t *current = get_coresp_branch(scaled_size, tree_size);
    free_metadata_t discover = current->tree;
    void *ptr = NULL;

    while (discover->size < scaled_size)
        discover = discover->next_free;
    ptr = split(discover, scaled_size);
    if (FREED_HEADER(discover)->prev_free) {
        repair_branch(current, discover);
    } else {
        if (discover->next_free)
            discover->next_free->prev_free = NULL;
        current->tree = discover->next_free;
    }
    HEADER(ptr)->free = 0;
    update_max_size(current);
    return ptr;
}