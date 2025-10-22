#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <limits.h>

enum
{
    MAX_DEPTH = 4
};

void
file_search(const char *dir_path, long max_size, int depth, const char *relative_path)
{

    if (depth > MAX_DEPTH) {
        return;
    }
    DIR *d = opendir(dir_path);
    if (d == NULL) {
        fprintf(stderr, "Error opening directory\n");
        return;
    }
    struct dirent *dd;
    while ((dd = readdir(d)) != NULL) {
        char *name = dd->d_name;
        if (strcmp(name, ".") != 0 && strcmp(name, "..") != 0) {
            char full_path[PATH_MAX];
            char new_relative_path[PATH_MAX];

            int snpr = snprintf(full_path, sizeof(full_path), "%s/%s", dir_path, name);
            if (snpr < 0 || snpr >= sizeof(full_path)) {
                fprintf(stderr, "Snprintf error\n");
                closedir(d);
                return;
            }

            if (relative_path[0] == '\0') {
                snpr = snprintf(new_relative_path, sizeof(new_relative_path), "%s", name);
                if (snpr < 0 || snpr >= sizeof(new_relative_path)) {
                    fprintf(stderr, "Snprintf error\n");
                    closedir(d);
                    return;
                }
            } else {
                snpr = snprintf(new_relative_path, sizeof(new_relative_path), "%s/%s", relative_path, name);
                if (snpr < 0 || snpr >= sizeof(new_relative_path)) {
                    fprintf(stderr, "Snprintf error\n");
                    closedir(d);
                    return;
                }
            }

            struct stat stb;
            if (lstat(full_path, &stb) == 0) {
                if (S_ISREG(stb.st_mode) && access(full_path, R_OK) == 0 && stb.st_size <= max_size) {
                    printf("%s\n", new_relative_path);
                } else if (S_ISDIR(stb.st_mode)) {
                    file_search(full_path, max_size, depth + 1, new_relative_path);
                }
            }
        }
    }
    closedir(d);
}

int
main(int argc, char *argv[])
{

    char *D = argv[1];
    long Z = atol(argv[2]);
    file_search(D, Z, 1, "");
    return 0;
}
