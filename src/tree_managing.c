/*
** EPITECH PROJECT, 2020
** my_malloc
** File description:
** manage trees
*/

#include "object.h"
#include "tools.h"

void remove_from_tree(free_metadata_t branch)
{
    bough_t *corresp = get_coresp_branch(branch->size, NOID);

    if (!branch->prev_free)
    {
        if (branch->next_free)
            branch->next_free->prev_free = NULL;
        corresp->tree = corresp->tree->next_free;
    }
    update_max_size(corresp);
}