#include <stdio.h>

#include "electriccar.h"

void ElectricCar_describe_impl(Automobile *obj)
{
    ElectricCar *this = (ElectricCar *) obj;

    Car_describe_impl((Automobile *) &this->parent);

    printf("Maximum range: %d miles\n", this->maximumRange);
}

struct vtbl ElectricCar_vtable = {
    ElectricCar_describe_impl,
    Automobile_testDrive_impl,
};

