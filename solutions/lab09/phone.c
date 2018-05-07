#include <stdio.h>
#include <stdlib.h>

#include <fcntl.h>
#include <unistd.h>

#include "commands.h"
#include "utils.h"
#include "faculty.h"

void usage(char *program)
{
    fprintf(stderr, "Usage: %s <file> <string>\n", program);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[])
{
    if (argc != 3) {
        usage(argv[0]);
    }

    read_file(argv[1]);

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

    print_professor(faculty + i);

    return EXIT_SUCCESS;
}
