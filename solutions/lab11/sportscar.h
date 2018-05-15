#ifndef _SPORTS_CAR_H
#define _SPORTS_CAR_H

#include "car.h"

typedef struct {
    Car parent;

    int topSpeed;
} SportsCar;

extern struct vtbl SportsCar_vtable;

#endif

