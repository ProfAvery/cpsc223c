#include <stdio.h>

#include "truck.h"

void Truck_describe_impl(Automobile *obj)
{
    Truck *this = (Truck *) obj;

    printf(
        "%d %s with %s drive type and %d miles.\n",
        this->parent.model,
        this->parent.make,
        this->driveType,
        this->parent.mileage
    );

    Automobile_describe_impl(&this->parent);
}

struct vtbl Truck_vtable = {
    Truck_describe_impl,
    Automobile_testDrive_impl,
};

