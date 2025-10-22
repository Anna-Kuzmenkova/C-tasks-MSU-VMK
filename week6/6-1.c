#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <limits.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>

int
suffix_check(const char *name)
{
    const char suf[] = ".exe";
    size_t suf_len = sizeof(suf) - 1;
    size_t name_len = strlen(name);

    if (name_len < suf_len) {
        return 0;
    }

    return strcmp(suf, name + name_len - suf_len) == 0;
}

int
main(int argc, char *argv[])
{

    const char *dir_path = argv[1];
    DIR *d = opendir(dir_path);
    if (d == NULL) {
        fprintf(stderr, "Error opening the directory\n");
        exit(1);
    }
    struct dirent *dd;
    struct stat stb;
    char path[PATH_MAX];
    int count = 0;

    while ((dd = readdir(d)) != NULL) {

        int full_path = snprintf(path, sizeof(path), "%s/%s", dir_path, dd->d_name);
        if (full_path < 0 || full_path >= sizeof(path)) {
            fprintf(stderr, "Snprintf error\n");
            closedir(d);
            exit(1);
        }
        int r = stat(path, &stb);
        if (r < 0) {
            fprintf(stderr, "Missing %s\n", path);
        } else if (S_ISREG(stb.st_mode) && (access(path, X_OK) == 0) && (suffix_check(dd->d_name))) {
            count++;
        }
    }
    closedir(d);
    printf("%d\n", count);
    return 0;
}
