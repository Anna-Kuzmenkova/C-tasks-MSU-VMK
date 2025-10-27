#include <stdio.h>

void
normalize_path(char *buf)
{

    if (buf == NULL || (buf[0] == '/' && buf[1] == '\0')) {
        return;
    }

    char *read = buf + 1;
    char *write = buf;
    int write_flag = 0;

    while (*read != '\0') {

        while (*read == '/') {
            read++;
        }
        if (*read == '\0') {
            break;
        }

        char *part = read;
        int len = 0;
        while (*read != '/' && *read != '\0') {
            read++;
            len++;
        }

        if (len == 1 && part[0] == '.') {
            continue;
        }

        if (len == 2 && part[0] == '.' && part[1] == '.') {

            if (write_flag) {
                write--;
                while (write > buf && *write != '/') {
                    write--;
                }
                if (write == buf) {
                    write_flag = 0;
                }
            }
            continue;
        }

        *write = '/';
        write++;
        write_flag = 1;
        for (int i = 0; i < len; ++i) {
            *write = part[i];
            write++;
        }
    }

    if (write_flag == 0) {
        *write = '/';
        write++;
    }
    *write = '\0';
}
