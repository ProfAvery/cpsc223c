#include "commands.h"
#include "faculty.h"

struct command commands[NUM_COMMANDS] = {
    { "email",  find_by_email},
    { "name",   find_by_name },
    { "office", find_by_office },
    { "phone",  find_by_phone },
};

int find_by_name(char *name)
{
    // REMOVE THE FOLLOWING LINE BEFORE ADDING YOUR CODE
    (void) name;

    // INSERT CODE HERE
    
    return -1;
}

int find_by_office(char *office)
{
    // REMOVE THE FOLLOWING LINE BEFORE ADDING YOUR CODE
    (void) office;

    // INSERT CODE HERE

    return -1;
}

int find_by_phone(char *phone)
{
    (void) phone;

    // INSERT CODE HERE

    return -1;
}

int find_by_email(char *email)
{
    (void) email;

    // INSERT CODE HERE
    
    return -1;
}

