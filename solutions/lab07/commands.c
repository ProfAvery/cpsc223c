#include <stdlib.h>
#include <string.h>

#include "commands.h"
#include "faculty.h"

struct command commands[NUM_COMMANDS] = {
    { "email",  find_by_email},
    { "name",   find_by_name },
    { "office", find_by_office },
    { "phone",  find_by_phone },
};

static int compare_name(const void *a, const void *b)
{
    const struct professor *pa = a;
    const struct professor *pb = b;

    return strcmp(pa->name, pb->name);
}

static int compare_office(const void *a, const void *b)
{
    const struct professor *pa = a;
    const struct professor *pb = b;

    return strcmp(pa->office, pb->office);
}

static int compare_phone(const void *a, const void *b)
{
    const struct professor *pa = a;
    const struct professor *pb = b;

    return strcmp(pa->phone, pb->phone);
}

static int compare_email(const void *a, const void *b)
{
    const struct professor *pa = a;
    const struct professor *pb = b;

    return strcmp(pa->email, pb->email);
}


int find_by_name(char *name)
{
    if (strlen(name) > FACULTY_NAME_LEN - 1) {
        return -1;
    }

    qsort(faculty, NUM_FACULTY, sizeof(struct professor), compare_name);

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

    qsort(faculty, NUM_FACULTY, sizeof(struct professor), compare_office);

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

    qsort(faculty, NUM_FACULTY, sizeof(struct professor), compare_phone);

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

    qsort(faculty, NUM_FACULTY, sizeof(struct professor), compare_email);

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

