#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#include "bstrlib.h"

#include "list.h"

bool verbose = false;

struct node *first_instruction;
struct node *current_instruction;

uint8_t byte = 0;

void do_step(void)
{
    if (current_instruction == NULL) {
        return;
    }

    if (biseqStatic(current_instruction->command, "set")) {
        byte = current_instruction->argument;
    } else if (biseqStatic(current_instruction->command, "and")) {
        byte &= current_instruction->argument;
    } else if (biseqStatic(current_instruction->command, "or")) {
        byte |= current_instruction->argument;
    } else if (biseqStatic(current_instruction->command, "xor")) {
        byte ^= current_instruction->argument;
    } else if (biseqStatic(current_instruction->command, "shr")) {
        byte >>= current_instruction->argument;
    } else if (biseqStatic(current_instruction->command, "shl")) {
        byte <<= current_instruction->argument;
    }

    if (verbose) {
        printf(
            "%s %x => %x\n",
            current_instruction->command->data,
            current_instruction->argument,
            byte
        );
    }

    current_instruction = current_instruction->next;
}

void do_continue(void)
{
    while (current_instruction != NULL) {
        do_step();
    }
}

void do_print(void)
{
    printf("%x\n", byte);
}

static struct node *find_prev(struct node *start)
{
    struct node *prev = first_instruction;

    while (prev->next != start) {
        prev = prev->next;
    }

    return prev;
}

void do_list(void)
{
    if (current_instruction == first_instruction) {
        print_node(current_instruction);
        print_node(current_instruction->next);
    } else if (current_instruction == NULL) {
        struct node *prev = find_prev(current_instruction);
        struct node *prevprev = find_prev(prev);

        print_node(prevprev);
        print_node(prev);
    } else {
        struct node *prev = find_prev(current_instruction);

        print_node(prev);
        print_node(current_instruction);
        print_node(current_instruction->next);
    }
}

