#ifndef COMMANDS_H
#define COMMANDS_H

#define NUM_COMMANDS 4

#define COMMAND_FILENAME_LEN 11

struct command {
    char filename[COMMAND_FILENAME_LEN];
    int (*function)(char *);
};

extern struct command commands[NUM_COMMANDS];

int compare_commands(const void *, const void*);

int find_by_name(char *);
int find_by_office(char *);
int find_by_phone(char *);
int find_by_email(char *);

#endif
