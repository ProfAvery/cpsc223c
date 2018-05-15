#include <stdio.h>

#include "automobile.h"

void Automobile_describe_impl(Automobile *this)
{
    printf("Price: $%9.2f\n", this->price);
}

void Automobile_testDrive_impl(Automobile *this, int length)
{
    this->mileage += length;
}

struct vtbl Automobile_vtable = {
    Automobile_describe_impl,
    Automobile_testDrive_impl,
};

