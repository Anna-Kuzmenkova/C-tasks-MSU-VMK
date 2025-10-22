#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

int
compare(const void *a, const void *b)
{
    return strcmp(*(const char **) a, *(const char **) b);
}

int
main(int argc, char *argv[])
{

    struct stat file_stats[argc];
    char *paths[argc];
    int cnt = 0;
    for (int i = 1; i < argc; ++i) {
        struct stat cur_stat;
        if (stat(argv[i], &cur_stat) == 0) {
            int found = 0;
            int j = 0;
            while (j < cnt && found == 0) {
                if (cur_stat.st_ino == file_stats[j].st_ino && cur_stat.st_dev == file_stats[j].st_dev) {
                    found = 1;
                    if (strcmp(paths[j], argv[i]) < 0) {
                        paths[j] = argv[i];
                    }
                }
                j++;
            }
            if (found == 0) {
                file_stats[cnt] = cur_stat;
                paths[cnt] = argv[i];
                cnt++;
            }
        }
    }

    qsort(paths, cnt, sizeof(*paths), compare);

    for (int i = 0; i < cnt; ++i) {
        printf("%s\n", paths[i]);
    }

    return 0;
}
