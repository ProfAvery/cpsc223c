#include "commands.h"
#include "faculty.h"

struct command commands[NUM_COMMANDS] = {
    { "email",  compare_by_email},
    { "name",   compare_by_name },
    { "office", compare_by_office },
    { "phone",  compare_by_phone },
};

int compare_by_name(char *name)
{
    (void) name;

    // INSERT CODE HERE
    
    return 0;
}

int compare_by_office(char *office)
{
    (void) office;

    // INSERT CODE HERE

    return 0;
}

int compare_by_phone(char *phone)
{
    (void) phone;

    // INSERT CODE HERE

    return 0;
}

int compare_by_email(char *email)
{
    (void) email;

    // INSERT CODE HERE
    
    return 0;
}

