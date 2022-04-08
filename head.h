#include <stdlib.h>

typedef struct RingInfo {
    size_t size;
    void (*add)(void*, void*, void*);
    void (*mult)(void*, void*, void*);

} RingInfo;

typedef struct Complex {
    float Re;
    float Im;
} Complex;

typedef struct Polynomial {
    int n;
    void* polynomial;
    RingInfo* rinfo;
} Polynomial;

RingInfo* create_rinfo(size_t, void (*add)(void*, void*, void*), void (*mult)(void*, void*, void*));

void add_int(void*, void*, void*);
void mult_int(void*, void*, void*);

void add_complex(void*, void*, void*);
void mult_complex(void*, void*, void*);

Polynomial* initialize();

void sum(Polynomial*, Polynomial*, Polynomial*);
void mult(Polynomial*, Polynomial*, Polynomial*);
void mult_scalar(void*, Polynomial*);
void value(Polynomial*, void*, void*);
void free_poly(Polynomial*);

void output_int(Polynomial*);
void output_complex(Polynomial*);

Polynomial* input_int(Polynomial*);
Polynomial* input_complex(Polynomial*);