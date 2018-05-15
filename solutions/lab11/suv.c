#include <stdio.h>

#include "suv.h"

void SUV_describe_impl(Automobile *obj)
{
    SUV *this = (SUV *) obj;

    printf(
        "%d %s with %d miles and %d passenger capacity.\n",
        this->parent.model,
        this->parent.make,
        this->parent.mileage,
        this->passengers
    );

    Automobile_describe_impl(&this->parent);
}

struct vtbl SUV_vtable = {
    SUV_describe_impl,
    Automobile_testDrive_impl,
};

