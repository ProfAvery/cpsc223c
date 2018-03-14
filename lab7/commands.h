#ifndef COMMANDS_H
#define COMMANDS_H

#define NUM_COMMANDS 4

#define COMMAND_NAME_LEN 7

struct command {
    char name[COMMAND_NAME_LEN];
    int (*function)(char *);
};

extern struct command commands[NUM_COMMANDS];

int find_by_name(char *);
int find_by_office(char *);
int find_by_phone(char *);
int find_by_email(char *);

#endif
