#include <stddef.h>

struct s1
{
    char f1;
    long long f2;
    char f3;
};

struct s2
{
    char f1;
    char f3;
    long long f2;
};

size_t
compactify(void *ptr, size_t size)
{

    size_t arr_cnt = size / sizeof(struct s1);

    struct s1 *old = (struct s1 *) ptr;
    struct s2 *new = (struct s2 *) ptr;

    for (size_t i = 0; i < arr_cnt; ++i) {
        new[i].f1 = old[i].f1;
        new[i].f2 = old[i].f2;
        new[i].f3 = old[i].f3;
    }

    return arr_cnt * sizeof(struct s2);
}
