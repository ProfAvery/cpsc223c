#ifndef COMMANDS_H
#define COMMANDS_H

#define NUM_COMMANDS 4

#define COMMAND_NAME_LEN 7

struct command {
    char name[COMMAND_NAME_LEN];
    int (*function)(char *);
};

extern struct command commands[NUM_COMMANDS];

int compare_by_name(char *);
int compare_by_office(char *);
int compare_by_phone(char *);
int compare_by_email(char *);

#endif
