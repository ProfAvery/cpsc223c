#ifndef _ELECTRIC_CAR_H
#define _ELECTRIC_CAR_H

#include "car.h"

typedef struct {
    Car parent;

    int maximumRange;
} ElectricCar;

extern struct vtbl ElectricCar_vtable;

#endif

