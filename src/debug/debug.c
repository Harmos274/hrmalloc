//
// Created by Lilian VERLHAC on 16/02/2020.
// Test my malloc

#include <unistd.h>

void iprint(size_t n)
{
    if (n > 9) {
        int a = n / 10;

        n -= 10 * a;
        iprint(a);
    }
    char c = '0' + n;
    write(1, &c, 1);
}

void dump(int scaling)
{
#ifdef _DUMP
    void *head = tree.root;
    size_t node_size = 0;
    size_t tiny_size = 0;
    size_t medium_size = 0;
    size_t large_size = 0;
    size_t gigantic_size = 0;

    write(1, "tiny = ", 7);
    for (free_metadata_t meta = tree.tiny_branch.tree; meta != NULL;
         meta = meta->next_free) {
        iprint(meta->size);
        write(1, "->", 2);
        ++tiny_size;
    }
    write(1, "\nmedium = ", 10);
    for (free_metadata_t meta = tree.medium_branch.tree; meta != NULL;
         meta = meta->next_free) {
        iprint(meta->size);
        write(1, "->", 2);
        ++medium_size;
    }
    write(1, "\nlarge = ", 10);
    for (free_metadata_t meta = tree.large_branch.tree; meta != NULL;
         meta = meta->next_free) {
        iprint(meta->size);
        write(1, "->", 2);
        ++large_size;
    }
    write(1, "\ngigantic = ", 12);
    for (free_metadata_t meta = tree.gigantic_branch.tree; meta != NULL;
         meta = meta->next_free) {
        iprint(meta->size);
        write(1, "->", 2);
        ++gigantic_size;
    }
    write(1, "\n", 1);
#ifdef _VISUAL_DUMP
    while (HEADER(head) != NULL) {
        node_size = HEADER(head)->size;
        if (HEADER(head)->free == 1)
            write(1, "\033[0;31m", 7);
        else
            write(1, "\033[0;32m", 7);
        for (size_t i = 0; i != node_size / (scaling * 16); i++) {
            write(1, "#", 1);
        }
        write(1, "||", 2);
        head = HEADER(head)->next;
    }
#endif
#ifdef _NUMERIC_DUMP
    while (HEADER(head) != NULL) {
        node_size = HEADER(head)->size;
        if (HEADER(head)->free == 1)
            write(1, "\033[0;31m", 7);
        else
            write(1, "\033[0;32m", 7);
        if (HEADER(head)->next && HEADER(head)->next->next == HEADER(head))
            _exit(1);
        write(1, "(", 1);
        iprint((unsigned int)head);
        write(1, ")", 1);
        iprint(node_size);
        write(1, "->", 2);
        head = HEADER(head)->next;
    }
#endif
#ifdef _ERROR_DUMP
    while (HEADER(head) != NULL) {
        if (HEADER(head)->next && HEADER(head)->next->next == HEADER(head))
            _exit(1);
        head = HEADER(head)->next;
    }
#endif
    write(1, "\ntree dump :\n", 13);
    write(1, "tiny tree max_size = ", 21);
    iprint(tree.tiny_branch.max_size);
    write(1, "\n", 1);
    write(1, "tiny tree nbr_branch = ", 23);
    iprint(tiny_size);
    write(1, "\n", 1);

    write(1, "medium tree max_size = ", 23);
    iprint(tree.medium_branch.max_size);
    write(1, "\n", 1);
    write(1, "medium tree nbr_branch = ", 25);
    iprint(medium_size);
    write(1, "\n", 1);

    write(1, "large tree max_size = ", 22);
    iprint(tree.large_branch.max_size);
    write(1, "\n", 1);
    write(1, "large tree nbr_branch = ", 24);
    iprint(large_size);
    write(1, "\n", 1);

    write(1, "gigantic tree max_size = ", 25);
    iprint(tree.gigantic_branch.max_size);
    write(1, "\n", 1);
    write(1, "gigantic tree nbr_branch = ", 27);
    iprint(gigantic_size);
    write(1, "\n\n", 2);
#endif
}