#include "include/my_malloc.h"
#include "include/macro.h"
#include <unistd.h>
#include <stdio.h>
#include <limits.h>
#include <string.h>

void dump(int);

int main(void)
{
    /* char *ptr = malloc(5); */
    /* size_t i = 5; */

    /* ptr[0] = 'a'; */
    /* ptr[1] = 'a'; */
    /* ptr[2] = 'a'; */
    /* ptr[3] = 'b'; */
    /* ptr[4] = 'c'; */

    /* while (1) */
    /* { */
        /* ptr[i] = 'd'; */
        /* write(1, "t\n", 2); */
        /* ++i; */
    /* } */
    void *ptr = malloc(500);
    void *ptr2 =malloc(128);
    free(ptr2);
    free(ptr);
    malloc(128);
    malloc(128);
    malloc(128);
    malloc(128);
    malloc(128);
    malloc(128);
    malloc(128);
    malloc(128);
    malloc(128);
    malloc(128);
    malloc(128);
    malloc(128);
    malloc(128);
    malloc(128);
    malloc(128);
    malloc(128);
    malloc(128);
    malloc(128);
    malloc(128);
    malloc(128);
    malloc(128);
    malloc(128);
    malloc(128);
    malloc(128);
    malloc(128);
    malloc(128);
    malloc(128);
    malloc(128);
    malloc(128);
    malloc(128);
    malloc(128);
    malloc(128);
    malloc(128);
    malloc(128);
    malloc(128);
    malloc(128);
    malloc(128);
    malloc(128);
    malloc(128);
    malloc(128);
    malloc(128);
    malloc(128);
    malloc(128);
    malloc(128);
    malloc(128);
    malloc(128);
    malloc(128);
    malloc(128);
    malloc(128);
    malloc(128);
    malloc(128);
    malloc(128);
    malloc(128);
    malloc(128);
    malloc(128);
    malloc(128);
    malloc(128);
    malloc(128);
    malloc(128);
    malloc(128);
    malloc(128);
    malloc(128);
    malloc(128);
    malloc(128);
    malloc(128);
    malloc(128);
    malloc(128);
    malloc(128);
    malloc(128);
    malloc(128);
    malloc(128);
    malloc(128);
    malloc(128);
    malloc(128);
    malloc(128);
    malloc(128);
    malloc(128);
    malloc(128);
    malloc(128);
    write(1, "\033[0m================ FINAL DUMP ==================================\n\n", 68);
    dump(2);
    return 0;
}
