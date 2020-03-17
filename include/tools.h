/*
** EPITECH PROJECT, 2020
** my_malloc
** File description:
** tools
*/

#ifndef TOOLS_H
#define TOOLS_H

#include "object.h"

alloc_type_t branch_selecta(size_t size);
bough_t *get_coresp_branch(size_t size, alloc_type_t branch_id);
void update_max_size(bough_t *list);
void *best_fitting_space(size_t scaled_size);



#endif // TOOLS_H
