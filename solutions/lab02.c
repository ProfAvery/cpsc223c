#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#define MAX_COMMAND_SIZE 3

uint8_t byte = 0;

int main(void)
{
    char command[MAX_COMMAND_SIZE + 1];
    unsigned int argument;

    while (scanf("%s %x", command, &argument) != EOF) {
        bool output = true;

        if (strcmp(command, "set") == 0) {
            byte = argument;
        } else if (strcmp(command, "and") == 0) {
            byte &= argument;
        } else if (strcmp(command, "or") == 0) {
            byte |= argument;
        } else if (strcmp(command, "xor") == 0) {
            byte ^= argument;
        } else if (strcmp(command, "shr") == 0) {
            byte >>= argument;
        } else if (strcmp(command, "shl") == 0) {
            byte <<= argument;
        } else {
            output = false;
        }

        if (output) {
            printf("%s %x => %x\n", command, argument, byte);
        }
    }

    return 0;
}
