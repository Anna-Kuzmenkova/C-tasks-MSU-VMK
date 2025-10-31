#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#include <limits.h>

int
main(int argc, char *argv[])
{

    if (argc != 3) {
        fprintf(stderr, "Incorrect data in command line arguments\n");
        exit(1);
    }

    const char *dir1 = argv[1];
    const char *dir2 = argv[2];
    DIR *d1 = opendir(dir1);
    if (d1 == NULL) {
        fprintf(stderr, "Error opening the first directory\n");
        exit(1);
    }

    struct dirent *dd1;
    off_t size = 0;

    while ((dd1 = readdir(d1)) != NULL) {

        if ((strcmp(dd1->d_name, ".") == 0) || (strcmp(dd1->d_name, "..") == 0)) {
            continue;
        }

        char path1[PATH_MAX];
        int full_path1 = snprintf(path1, sizeof(path1), "%s/%s", dir1, dd1->d_name);
        if (full_path1 < 0 || full_path1 >= sizeof(path1)) {
            fprintf(stderr, "Snprintf error\n");
            closedir(d1);
            exit(1);
        }

        struct stat stb1;
        int r1 = lstat(path1, &stb1);
        if (r1 < 0) {
            fprintf(stderr, "Missing %s\n", path1);
            continue;
        }
        int clone = 0;
        if (S_ISREG(stb1.st_mode) && (access(path1, W_OK) == 0)) {
            DIR *d2 = opendir(dir2);
            if (d2 == NULL) {
                fprintf(stderr, "Error opening the second directory\n");
                closedir(d1);
                exit(1);
            }
            struct dirent *dd2;
            while ((dd2 = readdir(d2)) != NULL) {

                if ((strcmp(dd2->d_name, ".") == 0) || (strcmp(dd2->d_name, "..") == 0)) {
                    continue;
                }

                char path2[PATH_MAX];
                int full_path2 = snprintf(path2, sizeof(path2), "%s/%s", dir2, dd2->d_name);
                if (full_path2 < 0 || full_path2 >= sizeof(path2)) {
                    fprintf(stderr, "Snprintf error\n");
                    closedir(d1);
                    closedir(d2);
                    exit(1);
                }

                struct stat stb2;
                int r2 = lstat(path2, &stb2);
                if (r2 < 0) {
                    fprintf(stderr, "Missing %s\n", path2);
                    continue;
                }

                int clone_flag = 0;
                if (S_ISLNK(stb2.st_mode)) {
                    char real1[PATH_MAX], real2[PATH_MAX];
                    if (realpath(path1, real1) && realpath(path2, real2) && strcmp(real1, real2) == 0) {
                        clone_flag = 1;
                    }
                } else if (S_ISREG(stb2.st_mode) && (stb1.st_ino == stb2.st_ino) && (stb1.st_dev == stb2.st_dev)) {
                    clone_flag = 1;
                }
                if (clone_flag) {
                    clone = 1;
                    break;
                }
            }
            closedir(d2);
            if (clone) {
                size += stb1.st_size;
            }
        }
    }
    closedir(d1);
    printf("%ld\n", size);
    return 0;
}
