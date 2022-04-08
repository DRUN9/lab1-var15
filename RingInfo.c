#include <stdlib.h>
#include "head.h"
#include <stdio.h>

RingInfo* create_rinfo(size_t size, void (*add)(void*, void*, void*), void (*mult)(void*, void*, void*)){
    RingInfo* rinfo = (RingInfo*)calloc(1, sizeof(RingInfo));

    rinfo->size = size;
    rinfo->add = add;
    rinfo->mult = mult;

    return rinfo;
}

void add_int(void* a, void* b, void* res){
    *(int*)res = *(int*)a + *(int*)b;
}

void mult_int(void* a, void* b, void* res){
    *(int*)res = (*(int*)a) * (*(int*)b);
}

void add_complex(void* a, void* b, void* res){
    ((Complex*)res)->Re = ((Complex*)a)->Re + ((Complex*)b)->Re;
    ((Complex*)res)->Im = ((Complex*)a)->Im + ((Complex*)b)->Im;
}

void mult_complex(void* a, void* b, void* res){
    Complex* rs;
    rs = calloc(1, sizeof(Complex));
    
    rs->Re = ((Complex*)a)->Re * ((Complex*)b)->Re - ((Complex*)a)->Im * ((Complex*)b)->Im;
    rs->Im = ((Complex*)a)->Re * ((Complex*)b)->Im + ((Complex*)a)->Im * ((Complex*)b)->Re;

    ((Complex*)res)->Re = rs->Re;
    ((Complex*)res)->Im = rs->Im;

    free(rs);
}
