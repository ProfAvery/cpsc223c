#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <fcntl.h>
#include <unistd.h>

#include "utils.h"
#include "faculty.h"

void check_error(int value, char *filename)
{
    if (value < 0) {
        perror(filename);
        exit(EXIT_FAILURE);
    }
}

void read_file(char *filename)
{
    int fd = open(filename, O_RDONLY);
    check_error(fd, filename);

    ssize_t bytes_read = read(fd, faculty, sizeof(faculty));
    check_error(bytes_read, filename);

    int result = close(fd);
    check_error(result, filename);
}

int compare_name(const void *a, const void *b)
{
    const struct professor *pa = a;
    const struct professor *pb = b;

    return strcmp(pa->name, pb->name);
}

int compare_office(const void *a, const void *b)
{
    const struct professor *pa = a;
    const struct professor *pb = b;

    return strcmp(pa->office, pb->office);
}

int compare_phone(const void *a, const void *b)
{
    const struct professor *pa = a;
    const struct professor *pb = b;

    return strcmp(pa->phone, pb->phone);
}

int compare_email(const void *a, const void *b)
{
    const struct professor *pa = a;
    const struct professor *pb = b;

    return strcmp(pa->email, pb->email);
}

