#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#define MAX_COMMAND_SIZE 3
#define PROGRAM_SIZE 13

struct statement {
    int line;
    char command[MAX_COMMAND_SIZE + 1];
    unsigned int argument;
};

struct statement program[] = {
    [0] = {  .line = 1,  .command = "set", .argument = 0x1  },
    [1] = {  .line = 2,  .command = "shl", .argument = 0x1  },
    [2] = {  .line = 3,  .command = "shl", .argument = 0x1  },
    [3] = {  .line = 4,  .command = "or",  .argument = 0x1  },
    [4] = {  .line = 5,  .command = "or",  .argument = 0x2  },
    [5] = {  .line = 6,  .command = "shl", .argument = 0x2  },
    [6] = {  .line = 7,  .command = "xor", .argument = 0x10 },
    [7] = {  .line = 8,  .command = "xor", .argument = 0x10 },
    [8] = {  .line = 9,  .command = "and", .argument = 0x4  },
    [9] = {  .line = 10, .command = "set", .argument = 0x1c },
    [10] = { .line = 11, .command = "and", .argument = 0x3  },
    [11] = { .line = 12, .command = "set", .argument = 0x1c },
    [12] = { .line = 13, .command = "shr", .argument = 0x1  },
};

int counter = 0;

uint8_t byte = 0;

void do_step()
{
    if (counter >= PROGRAM_SIZE) {
        return;
    }

    struct statement next = program[counter++];

    if (strcmp(next.command, "set") == 0) {
        byte = next.argument;
    } else if (strcmp(next.command, "and") == 0) {
        byte &= next.argument;
    } else if (strcmp(next.command, "or") == 0) {
        byte |= next.argument;
    } else if (strcmp(next.command, "xor") == 0) {
        byte ^= next.argument;
    } else if (strcmp(next.command, "shr") == 0) {
        byte >>= next.argument;
    } else if (strcmp(next.command, "shl") == 0) {
        byte <<= next.argument;
    }
}

void do_continue()
{
    for (int i = counter; i < PROGRAM_SIZE; i++) {
        do_step();
    }
}

void do_print()
{
    printf("%x\n", byte);
}

void print_statement(int i)
{
    printf("%2d %s %x\n", program[i].line, program[i].command, program[i].argument);
}

void do_list()
{
    if (counter == 0) {
        print_statement(counter);
        print_statement(counter + 1);
    } else if (counter >= PROGRAM_SIZE - 1) {
        print_statement(PROGRAM_SIZE - 2);
        print_statement(PROGRAM_SIZE - 1);
    } else {
        print_statement(counter - 1);
        print_statement(counter);
        print_statement(counter + 1);
    }
}

int main(void)
{
    char command[MAX_COMMAND_SIZE + 1];

    while (scanf("%s", command) != EOF) {

        if (strcmp(command, "step") == 0) {
            do_step();
        } else if (strcmp(command, "continue") == 0) {
            do_continue();
        } else if (strcmp(command, "print") == 0) {
            do_print();
        } else if (strcmp(command, "list") == 0) {
            do_list();
        }

    }

    return 0;
}
