#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "commands.h"
#include "faculty.h"

void usage(char *program)
{
    fprintf(stderr, "Usage: %s <command> <string>\n", program);
    exit(EXIT_FAILURE);
}

int compare_commands(const void *a, const void *b)
{
    const struct command *ca = a;
    const struct command *cb = b;

    return strcmp(ca->name, cb->name);
}

int main(int argc, char *argv[])
{
    if (argc != 3) {
        usage(argv[0]);
    }

    if (strlen(argv[1]) > COMMAND_NAME_LEN - 1) {
        usage(argv[0]);
    }

    struct command *found = bsearch(
        argv[1],
        commands,
        NUM_COMMANDS,
        sizeof(struct command),
        compare_commands
    );
    if (found == NULL) {
        usage(argv[0]);
    }

    int i = found->function(argv[2]);
    if (i < 0) {
        printf("No match.\n");
        exit(EXIT_FAILURE);
    }

    printf(
        "%s\n%s\n%s\n%s\n",
        faculty[i].name,
        faculty[i].office,
        faculty[i].phone,
        faculty[i].email
    );

    return EXIT_SUCCESS;
}
