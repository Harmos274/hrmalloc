/*
** EPITECH PROJECT, 2020
** my_malloc
** File description:
** tools
*/

#define _MALLOC_GLOBAL
#include "my_malloc.h"
#include "object.h"
#include "prune_tree.h"
#include <unistd.h>

alloc_type_t branch_selecta(size_t size)
{
    int i = 0;
    struct {int type; size_t treshold; } const treshold[] = {
        {TINY, TINY_BOUND},
        {MEDIUM, MEDIUM_BOUND},
        {LARGE, LARGE_BOUND},
        {GIGANTIC, GIGANTIC_BOUND}
    };

    while (1) {
        if (size <= treshold[i].treshold)
            return treshold[i].type;
    }
}

bough_t *get_coresp_branch(size_t size, alloc_type_t branch_id)
{
    bough_t *tree_branches[4] = {&tree.tiny_branch, &tree.medium_branch,
                                 &tree.large_branch, &tree.gigantic_branch};
    bough_t *ret = NULL;
    if (branch_id != NOID)
        ret =  tree_branches[branch_id];
    else
        ret = tree_branches[branch_selecta(size)];
    return ret;
}

void update_max_size(bough_t *list)
{
    free_metadata_t discover = list->tree;

    list->max_size = 0;
    if (discover) {
        while (discover->next_free != NULL) {
            discover = discover->next_free;
        }
        list->max_size = discover->size;
    }
}

void *create_new_chunk(size_t scaled_size)
{
    metadata_t discover = tree.root;
    metadata_t new_header;

    while (discover->next != NULL)
        discover = discover->next;
    new_header = (metadata_t)NEXTHEADER(discover);
    if ((sbrk(0) - (void *)new_header) <= (long)scaled_size) {
        sbrk(TOTAL_PAGE_SIZE(scaled_size - (sbrk(0) - (void *)new_header)));
    }
    new_header->free = 0;
    new_header->next = NULL;
    new_header->size = scaled_size;
    discover->next = new_header;
    return new_header;
}

void *best_fitting_space(size_t scaled_size)
{
    int i = 0;
    struct {int type; size_t treshold; } const treshold[] = {
        {TINY, tree.tiny_branch.max_size},
        {MEDIUM, tree.medium_branch.max_size},
        {LARGE, tree.large_branch.max_size},
        {GIGANTIC, tree.gigantic_branch.max_size}
    };

    while (i < 4) {
        if (scaled_size <= treshold[i].treshold) {
            return prune_tree(scaled_size, treshold[i].type);
        }
        ++i;
    }
    return create_new_chunk(scaled_size);
}