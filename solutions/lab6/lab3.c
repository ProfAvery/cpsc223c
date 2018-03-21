#include <stdio.h>
#include <stdint.h>

#include "bstrlib.h"
#include "checks.h"

#define PROGRAM_SIZE ((int) (sizeof(program) / sizeof(struct statement)))

struct statement {
    int line;
    struct tagbstring command;
    unsigned int argument;
};

struct statement program[] = {
    [0] = {  .line = 1,  .command = bsStatic("set"), .argument = 0x1  },
    [1] = {  .line = 2,  .command = bsStatic("shl"), .argument = 0x1  },
    [2] = {  .line = 3,  .command = bsStatic("shl"), .argument = 0x1  },
    [3] = {  .line = 4,  .command = bsStatic("or"),  .argument = 0x1  },
    [4] = {  .line = 5,  .command = bsStatic("or"),  .argument = 0x2  },
    [5] = {  .line = 6,  .command = bsStatic("shl"), .argument = 0x2  },
    [6] = {  .line = 7,  .command = bsStatic("xor"), .argument = 0x10 },
    [7] = {  .line = 8,  .command = bsStatic("xor"), .argument = 0x10 },
    [8] = {  .line = 9,  .command = bsStatic("and"), .argument = 0x4  },
    [9] = {  .line = 10, .command = bsStatic("set"), .argument = 0x1c },
    [10] = { .line = 11, .command = bsStatic("and"), .argument = 0x3  },
    [11] = { .line = 12, .command = bsStatic("set"), .argument = 0x1c },
    [12] = { .line = 13, .command = bsStatic("shr"), .argument = 0x1  },
};

int counter = 0;

uint8_t byte = 0;

void do_step()
{
    if (counter >= PROGRAM_SIZE) {
        return;
    }

    struct statement next = program[counter++];

    if (biseqStatic(&next.command, "set")) {
        byte = next.argument;
    } else if (biseqStatic(&next.command, "and")) {
        byte &= next.argument;
    } else if (biseqStatic(&next.command, "or")) {
        byte |= next.argument;
    } else if (biseqStatic(&next.command, "xor")) {
        byte ^= next.argument;
    } else if (biseqStatic(&next.command, "shr")) {
        byte >>= next.argument;
    } else if (biseqStatic(&next.command, "shl")) {
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
    printf("%2d %s %x\n", program[i].line, program[i].command.data, program[i].argument);
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

bstring gets(void)
{
    bstring s = bgets((bNgetc) fgetc, stdin, '\n');
    if (s != NULL) {
        int len = blength(s) - 1;
        CHECK_BSTR_OK(btrunc(s, len));
    }

    return s;
}

int main(void)
{
    bstring command;

    while ((command = gets()) != NULL) {

        if (biseqStatic(command, "step")) {
            do_step();
        } else if (biseqStatic(command, "continue")) {
            do_continue();
        } else if (biseqStatic(command, "print")) {
            do_print();
        } else if (biseqStatic(command, "list")) {
            do_list();
        }

        CHECK_BSTR_OK(bdestroy(command));
    }

    return 0;
}
