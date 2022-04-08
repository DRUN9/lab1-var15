#include "head.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

Polynomial* initialize(){
    Polynomial* p = (Polynomial*)calloc(1, sizeof(Polynomial));

    p->n = 0;
    p->polynomial = NULL;
    p->rinfo = NULL;

    return p;
}

void sum(Polynomial* p1, Polynomial* p2, Polynomial* res){
    if (res->polynomial){
        free(res->polynomial);
    }

    int nmin, nmax, ind;

    if (p1->n <= p2->n){
        nmin = p1->n;
        nmax = p2->n;
        ind = 1;
    }
    else{
        nmin = p2->n;
        nmax = p1->n;
        ind = 0;
    }

    res->n = nmax;
    res->polynomial = calloc(nmax, res->rinfo->size);

    for(int i = 0; i < nmax; i++){
        if (i < nmin){
            res->rinfo->add(p1->polynomial + i * p1->rinfo->size, p2->polynomial + i * p2->rinfo->size, res->polynomial + i * res->rinfo->size);
        }
        else if (ind == 0){
            memcpy(res->polynomial + i * res->rinfo->size, p1->polynomial + i * p1->rinfo->size, res->rinfo->size);
        }
        else{
            memcpy(res->polynomial + i * res->rinfo->size, p2->polynomial + i * p2->rinfo->size, res->rinfo->size);
        }
    }
}

void mult_scalar(void* scalar, Polynomial* res){
    for(int i = 0; i < res->n; i++){
        res->rinfo->mult(scalar, res->polynomial + i * res->rinfo->size, res->polynomial + i * res->rinfo->size);
    }
}

void mult(Polynomial* p1, Polynomial* p2, Polynomial* res){
    if (res->polynomial){
        free(res->polynomial);
    }

    res->n = p1->n + p2->n - 1;
    res->polynomial = calloc(res->n, res->rinfo->size);

    for(int i = 0; i < p1->n; i++){
        for (int j = 0; j < p2->n; j++){
                void* r;
                r = calloc(1, res->rinfo->size);
                res->rinfo->mult(p1->polynomial + i * p1->rinfo->size, p2->polynomial + j * p2->rinfo->size, r);
                res->rinfo->add(res->polynomial + (i + j) * res->rinfo->size, r, res->polynomial + (i + j) * res->rinfo->size);
                free(r);
        }
    }
}

void value(Polynomial* p, void* x, void* res){
    for (int i = 0; i < p->n; i++){
        if (i == 0){
            memcpy(res, p->polynomial + i * p->rinfo->size, p->rinfo->size);
        }
        else{
            int k = i;
            void* r;
            r = calloc(1, p->rinfo->size);
            memcpy(r, x, p->rinfo->size);
            while(k > 1){
                p->rinfo->mult(r, x, r);
                k--;
            }
            p->rinfo->mult(p->polynomial + i * p->rinfo->size, r, r);
            p->rinfo->add(res, r, res);
            free(r);
        }
    }
}

void free_poly(Polynomial* p){
    if (p->polynomial){
        free(p->polynomial);
    }
    free(p);
}