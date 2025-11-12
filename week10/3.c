#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

enum
{
    MAX_LEN = 9,
    STR_NUM = 3,
    RADIX = 10
};

int
main(void)
{

    pid_t pid;
    char str[MAX_LEN];

    for (int i = 0; i < STR_NUM; ++i) {

        if (fgets(str, sizeof(str), stdin) == NULL) {
            fprintf(stderr, "Error reading line\n");
            exit(1);
        }

        int fd[2];
        if (pipe(fd) < 0) {
            fprintf(stderr, "Pipe error\n");
            exit(1);
        }

        pid = fork();
        if (pid < 0) {

            fprintf(stderr, "Fork error\n");
            exit(1);

        } else if (!pid) {

            close(fd[1]);
            char buf[MAX_LEN];
            if (read(fd[0], buf, sizeof(buf)) <= 0) {
                close(fd[0]);
                fprintf(stderr, "Read error\n");
                _exit(1);
            }
            close(fd[0]);

            long int num;
            char *eptr = NULL;
            errno = 0;
            num = strtol(buf, &eptr, RADIX);
            if (errno || eptr == buf) {
                fprintf(stderr, "Incorrect command line arguments: error converting a string to a number\n");
                _exit(1);
            }

            printf("%d %ld\n", i + 1, num * num);
            if (fflush(stdout) != 0) {
                fprintf(stderr, "Fflush error\n");
                _exit(1);
            }
            _exit(0);

        } else {

            close(fd[0]);
            if (write(fd[1], str, sizeof(str)) < 0) {
                fprintf(stderr, "Write error\n");
                exit(1);
            }
            close(fd[1]);
        }
    }

    while (wait(NULL) > 0) {
    }

    return 0;
}
