#include <stdio.h>
#include <stdlib.h>

int
compare(const void *arg1, const void *arg2)
{
    int num_1 = *(int *) arg1;
    int num_2 = *(int *) arg2;

    int odd_1 = num_1 & 1;
    int odd_2 = num_2 & 1;
    int even_1 = !odd_1;
    int even_2 = !odd_2;

    if (even_1 && odd_2) {
        return -1;
    }
    if (odd_1 && even_2) {
        return 1;
    }

    if (even_1 && even_2) {
        if (num_1 > num_2) {
            return 1;
        }
        if (num_1 < num_2) {
            return -1;
        }
        return 0;
    }

    if (odd_1 && odd_2) {
        if (num_1 < num_2) {
            return 1;
        }
        if (num_1 > num_2) {
            return -1;
        }
        return 0;
    }
    return 0;
}

void
sort_even_odd(size_t count, int *data)
{
    qsort(data, count, sizeof(*data), compare);
}
