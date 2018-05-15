#include <stdio.h>

#include "car.h"

void Car_describe_impl(Automobile *obj)
{
    Car *this = (Car *) obj;

    printf(
        "%d %s with %d doors and %d miles.\n",
        this->parent.model,
        this->parent.make,
        this->doors,
        this->parent.mileage
    );

    Automobile_describe_impl(&this->parent);
}

struct vtbl Car_vtable = {
    Car_describe_impl,
};

