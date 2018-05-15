#ifndef _SUV_H
#define _SUV_H

#include "automobile.h"

typedef struct SUV {
    Automobile parent;

    int passengers;
} SUV;

extern struct vtbl SUV_vtable;

#endif

