#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>

enum
{
    BUF_SIZE = 4,
    SHIFT_BY_TWELVE = 12,
    SHIFT_BY_EIGHT = 8,
    MASK_1 = 0xFFF,
    MASK_2 = 0x0F,
    MASK_3 = 0xFF
};

int
main(int argc, char *argv[])
{
    if (argc < 2) {
        fprintf(stderr, "There is no output file in the command line\n");
        exit(1);
    }

    int output_fd = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, 0600);
    if (output_fd < 0) {
        fprintf(stderr, "Error opening file\n");
        exit(1);
    }

    unsigned int num;
    while (scanf("%u", &num) == 1) {

        unsigned char buf[BUF_SIZE];
        unsigned int high = (num >> SHIFT_BY_TWELVE) & MASK_1;
        unsigned int low = num & MASK_1;
        buf[0] = (high >> SHIFT_BY_EIGHT) & MASK_2;
        buf[1] = high & MASK_3;
        buf[2] = (low >> SHIFT_BY_EIGHT) & MASK_2;
        buf[3] = low & MASK_3;

        if (write(output_fd, buf, BUF_SIZE) < 0) {
            fprintf(stderr, "Error writing in file\n");
            exit(1);
        }
    }
    close(output_fd);
    return 0;
}
