#ifndef _AUTOMOBILE_H
#define _AUTOMOBILE_H

struct vtbl; // forward declaration

// class Automobile
typedef struct {
    struct vtbl *vptr;

    char *make;
    int model;
    int mileage;
    double price;

} Automobile;

struct vtbl {
    void (*describe)(Automobile *);
};

extern struct vtbl Automobile_vtable;

void Automobile_describe_impl(Automobile *);

#endif

