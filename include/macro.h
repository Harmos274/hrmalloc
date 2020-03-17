/*
** EPITECH PROJECT, 2020
** my malloc
** File description:
** maccro for malloc
*/

#ifndef MACRO_H_
#define MACRO_H_

// calcul macro

#define SCALE_SIZE(size, scaler) (((size / scaler) + 1) * scaler)
#define TOTAL_PAGE_SIZE(size) \
    (((((size) / (2 * getpagesize())) + 1) * 2 * getpagesize()))
#define HEADER(ptr) ((metadata_t)(ptr))
#define FREED_HEADER(ptr) ((free_metadata_t)(ptr))
#define START(ptr) (((char *)ptr) - SIZE_HEADER)
#define CHUNK(ptr) (((char *)ptr) + SIZE_HEADER)

#define NEXTHEADER(ptr) (((char *)ptr) + ptr->size)

// error messages

#define ERR_DOUBLE_FREE "free() : double free or corruption detected.\n"

#endif
