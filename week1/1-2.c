#include <stdio.h>

enum
{

    NUM_OFFSET = 1,
    LOW_OFFSET = 11,
    UP_OFFSET = 37,

    MIN_CODE_NUM = 0,
    MAX_CODE_NUM = 63,

    MIN_CODE_SYM = '@',
    MAX_CODE_SYM = '#',

    NUM_START = '0',
    NUM_END = '9',
    LOW_LETTER_START = 'a',
    LOW_LETTER_END = 'z',
    UP_LETTER_START = 'A',
    UP_LETTER_END = 'Z',

    BIT_SET = 1,
    SECOND_BIT = 2,
    THIRD_BIT = 3

};

int
main(void)
{

    int c;
    while ((c = getchar()) != EOF) {
        int code = 0;
        if (c >= NUM_START && c <= NUM_END) {
            code = c - NUM_START + NUM_OFFSET;
        } else if (c >= LOW_LETTER_START && c <= LOW_LETTER_END) {
            code = c - LOW_LETTER_START + LOW_OFFSET;
        } else if (c >= UP_LETTER_START && c <= UP_LETTER_END) {
            code = c - UP_LETTER_START + UP_OFFSET;
        } else {
            continue;
        }

        int mask1 = ~(BIT_SET << SECOND_BIT);
        int mask2 = BIT_SET << THIRD_BIT;
        code &= mask1;
        code ^= mask2;

        if (code == MIN_CODE_NUM) {
            putchar(MIN_CODE_SYM);
        } else if (code == MAX_CODE_NUM) {
            putchar(MAX_CODE_SYM);
        } else if (code < LOW_OFFSET) {
            putchar(NUM_START + code - NUM_OFFSET);
        } else if (code < UP_OFFSET) {
            putchar(LOW_LETTER_START + code - LOW_OFFSET);
        } else {
            putchar(UP_LETTER_START + code - UP_OFFSET);
        }
    }
    putchar('\n');
    return 0;
}
