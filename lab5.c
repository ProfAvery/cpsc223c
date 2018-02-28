// lab5.c - starter code for Lab 5

/*
 * Complete the definitions for the stack_*() functions so that main()
 * prints the reverse of its command-line arguments. For example:
 *
 *  $ ./reverse foo bar baz
 *  zab rab oof
 *
 * Be sure that your code passes "--leak-check=full" with Valgrind.
 *
 */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack {
    struct stack_element *top;
    int element_count;
};

struct stack_element {
    unsigned char c;
    struct stack_element *next;
};

struct stack *stack_create(void)
{
    struct stack *s = malloc(sizeof(struct stack));
    if (s == NULL) {
        fprintf(stderr, "%s:%d: malloc() returned NULL\n", __FILE__, __LINE__);
        exit(EXIT_FAILURE);
    }

    // INSERT CODE HERE

    return s;
}

void stack_destroy(struct stack *s)
{
    assert(s != NULL);

    // INSERT CODE HERE
}

void stack_push(struct stack *s, unsigned char c)
{
    assert(s != NULL);

    // INSERT CODE HERE
}

int stack_pop(struct stack *s)
{
    assert(s != NULL);

    unsigned char c;

    // INSERT CODE HERE

    return c;
}

int main(int argc, char *argv[])
{
    struct stack *s = stack_create();

    for (int i = argc - 1; i > 0; i--) {
        char *arg = argv[i];

        for (size_t j = 0; j < strlen(arg); j++) {
            stack_push(s, arg[j]);
        }

        char c;
        while ((c = stack_pop(s)) != EOF) {
            printf("%c", c);
        }

        printf(" ");
    }
    printf("\n");

    stack_destroy(s);

    return EXIT_SUCCESS;
}
