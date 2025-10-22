#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <limits.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

int
parse_rwx_permissions(const char *str)
{

    if (str == NULL) {
        return -1;
    }
    const char template[] = "rwxrwxrwx";
    const int template_len = sizeof(template) - 1;

    if (strlen(str) != template_len) {
        return -1;
    }

    int res = 0;

    for (int i = 0; i < template_len; ++i) {
        if (str[i] == template[i]) {
            res |= (1 << (template_len - 1 - i));
        } else if (str[i] != '-') {
            return -1;
        }
    }

    return res;
}
