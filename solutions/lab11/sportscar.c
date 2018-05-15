#include <stdio.h>

#include "sportscar.h"

void SportsCar_describe_impl(Automobile *obj)
{
    SportsCar *this = (SportsCar *) obj;

    Car_describe_impl((Automobile *) &this->parent);

    printf("Top speed: %dmph\n", this->topSpeed);
}

struct vtbl SportsCar_vtable = {
    SportsCar_describe_impl,
    Automobile_testDrive_impl,
};

