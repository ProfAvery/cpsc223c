// lab1.cpp - convert this code to C11

/*
 *  This code should compile cleanly with the following options:
 *
 
    C:   -std=c11   -g -Wall -Wextra -Wpedantic

    C++: -std=c++11 -g -Wall -Wextra -Wpedantic

 */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "bstrlib.h"
#include "checks.h"


void bump_int(int *i, int *amount)
{
    assert (i != NULL);

    if (amount == NULL) {
        *i += 1;
    } else {
        *i += *amount;
    }
}

void bump_string(bstring s, char *c)
{
    assert (s != NULL);

    char new = (c == NULL)? 'o' : *c;

    CHECK_BSTR_OK(bconchar(s, new));
}

int main(void)
{
    int i = 1;

    printf("%d\n", i);
    bump_int(&i, NULL);
    printf("%d\n", i);

    int amount = 2;
    bump_int(&i, &amount);
    printf("%d\n", i);

    bstring s;
    CHECK_NOT_NULL(s = bfromStatic("foo"));

    printf("%s\n", s->data);
    bump_string(s, NULL);
    printf("%s\n", s->data);

    char c = 'x';
    bump_string(s, &c);
    printf("%s\n", s->data);

    CHECK_BSTR_OK(bdestroy(s));

    return 0;
}

