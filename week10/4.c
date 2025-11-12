#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int
main(int argc, char *argv[])
{

    int n;
    if (scanf("%d", &n) != 1) {
        fprintf(stderr, "Error reading data from input stream\n");
        exit(1);
    }
    if (n <= 0) {
        fprintf(stderr, "Incorect input data: n must be a positive number\n");
        exit(1);
    }

    pid_t pid;
    for (int i = 1; i <= n; ++i) {
        if (i == n) {
            printf("%d\n", i);
            if (fflush(stdout) != 0) {
                fprintf(stderr, "Fflush error\n");
                exit(1);
            }
            return 0;
        } else {
            printf("%d ", i);
            if (fflush(stdout) != 0) {
                fprintf(stderr, "Fflush error\n");
                exit(1);
            }
        }
        if ((pid = fork()) < 0) {
            fprintf(stderr, "Fork error\n");
            exit(1);
        } else if (!pid) {
            wait(NULL);
            break;
        }
    }
    return 0;
}
