#ifndef _TRUCK_H
#define _TRUCK_H

#include "automobile.h"

typedef struct {
    Automobile parent;

    char *driveType;
} Truck;

extern struct vtbl Truck_vtable;

#endif

