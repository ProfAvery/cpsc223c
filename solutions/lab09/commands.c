#include <stdlib.h>
#include <string.h>

#include "commands.h"
#include "utils.h"
#include "faculty.h"

struct command commands[NUM_COMMANDS] = {
    { "email.bin",  find_by_email },
    { "name.bin",   find_by_name },
    { "office.bin", find_by_office },
    { "phone.bin",  find_by_phone },
};

int compare_commands(const void *a, const void *b)
{
    const struct command *ca = a;
    const struct command *cb = b;

    return strcmp(ca->filename, cb->filename);
}

int find_by_name(char *name)
{
    if (strlen(name) > FACULTY_NAME_LEN - 1) {
        return -1;
    }

    struct professor p;
    strcpy(p.name, name);

    struct professor *found = bsearch(
        &p,
        faculty,
        NUM_FACULTY,
        sizeof(struct professor),
        compare_name
    );
    if (found == NULL) {
        return -1;
    }
    
    return found - faculty;
}

int find_by_office(char *office)
{
    if (strlen(office) > FACULTY_OFFICE_LEN - 1) {
        return -1;
    }

    struct professor p;
    strcpy(p.office, office);

    struct professor *found = bsearch(
        &p,
        faculty,
        NUM_FACULTY,
        sizeof(struct professor),
        compare_office
    );
    if (found == NULL) {
        return -1;
    }
    
    return found - faculty;
}

int find_by_phone(char *phone)
{
    if (strlen(phone) > FACULTY_PHONE_LEN - 1) {
        return -1;
    }

    struct professor p;
    strcpy(p.phone, phone);

    struct professor *found = bsearch(
        &p,
        faculty,
        NUM_FACULTY,
        sizeof(struct professor),
        compare_phone
    );
    if (found == NULL) {
        return -1;
    }
    
    return found - faculty;
}

int find_by_email(char *email)
{
    if (strlen(email) > FACULTY_EMAIL_LEN - 1) {
        return -1;
    }

    struct professor p;
    strcpy(p.email, email);

    struct professor *found = bsearch(
        &p,
        faculty,
        NUM_FACULTY,
        sizeof(struct professor),
        compare_email
    );
    if (found == NULL) {
        return -1;
    }
    
    return found - faculty;
}

