/*
** EPITECH PROJECT, 2020
** my_malloc
** File description:
** prune trees header
*/

#ifndef PRUNE_TREE_H_
#define PRUNE_TREE_H_

#include "object.h"
#include "macro.h"

void update_max_size(bough_t *list);
void *split(free_metadata_t ptr, size_t scaled_size);
void *prune_tree(size_t scaled_size, alloc_type_t tree_size);

#endif
