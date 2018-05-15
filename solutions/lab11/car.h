#ifndef _CAR_H
#define _CAR_H

#include "automobile.h"

typedef struct {
    Automobile parent;

    int doors;
} Car;

extern struct vtbl Car_vtable;

void Car_describe_impl(Automobile *);

#endif

