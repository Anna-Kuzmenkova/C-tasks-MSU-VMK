#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int
main(int argc, char *argv[])
{

    pid_t pid_son, pid_grson;
    if ((pid_son = fork()) < 0) {
        fprintf(stderr, "Fork error\n");
        exit(1);
    } else if (!pid_son) {
        if ((pid_grson = fork()) < 0) {
            fprintf(stderr, "Fork error\n");
            exit(1);
        } else if (!pid_grson) {
            printf("3 ");
        } else {
            wait(NULL);
            printf("2 ");
        }
    } else {
        wait(NULL);
        printf("1\n");
    }

    return 0;
}
