#include <stdio.h>

#include "automobile.h"

void Automobile_describe_impl(Automobile *this)
{
    printf("Price: $%g\n", this->price);
}

struct vtbl Automobile_vtable = {
    Automobile_describe_impl,
};

