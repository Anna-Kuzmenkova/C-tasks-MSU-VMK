#include <stdio.h>
#include <stdlib.h>

enum
{
    MIN_N = 2,
    MAX_N = 2000
};

int
inverse(int a, int n)
{

    int r0 = n, r1 = a;
    int s0 = 0, s1 = 1;
    int q = 0, temp = 0;

    while (r1 != 0) {
        q = r0 / r1;

        temp = r1;
        r1 = r0 - q * r1;
        r0 = temp;

        temp = s1;
        s1 = s0 - q * s1;
        s0 = temp;
    }

    if (s0 < 0) {
        s0 += n;
    }
    return s0;
}

int
prime(int x)
{

    if (x < 2) {
        return 0;
    }
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            return 0;
        }
    }
    return 1;
}

int
main(void)
{

    int n = 0;
    if (scanf("%d", &n) != 1) {
        fprintf(stderr, "failed to read one int\n");
        exit(1);
    }
    if (n < MIN_N || n >= MAX_N || !prime(n)) {
        fprintf(stderr, "incorrect input data: N must be prime and N < 2000\n");
        exit(1);
    }

    for (int c = 0; c < n; c++) {
        for (int a = 1; a < n; a++) {
            int inv_a = inverse(a, n);
            int b = (inv_a * c) % n;
            printf("%d ", b);
        }
        printf("\n");
    }

    return 0;
}
