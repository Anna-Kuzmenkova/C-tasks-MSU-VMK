#include <stdio.h>
#include <stdlib.h>

enum
{
    MAX_N = 9,
    MIN_N = 1
};

void
swap(int *a, int *b)
{

    int temp = *a;
    *a = *b;
    *b = temp;
}

int
permutations(int *array, int n)
{

    int i = n - 2;
    while (i != -1 && array[i] >= array[i + 1]) {
        i--;
    }
    if (i == -1) {
        return 1;
    }

    int j = n - 1;
    while (array[i] >= array[j]) {
        j--;
    }
    swap(&array[i], &array[j]);

    int left = i + 1, right = n - 1;
    while (left < right) {
        swap(&array[left], &array[right]);
        left++;
        right--;
    }

    return 0;
}

void
print_array(int *array, int n)
{

    for (int i = 0; i < n; i++) {
        printf("%d", array[i]);
    }
    printf("\n");
}

int
main(void)
{

    int n;
    if (scanf("%d", &n) != 1) {
        fprintf(stderr, "failed to read one int\n");
        exit(1);
    }

    if (n < MIN_N || n > MAX_N) {
        fprintf(stderr, "incorrect input data: N must be between 1 and 9\n");
        exit(1);
    }

    int numbers[MAX_N];
    for (int i = 0; i < n; i++) {
        numbers[i] = i + 1;
    }
    print_array(numbers, n);

    while (n > 1 && permutations(numbers, n) != 1) {
        print_array(numbers, n);
    }

    return 0;
}
