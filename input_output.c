#include <stdio.h>
#include <time.h>
#include "head.h"


void output_int(Polynomial* p){
    if (!p->polynomial){
        printf("Polynomial is empty\n");
        return;
    }

    for(int i = p->n - 1; i >= 0; i--){
        if(i != 0){
            printf("%d * x ^ %d + ", *(int*)(p->polynomial + i * p->rinfo->size), i);
        }
        else{
            printf("%d\n", *(int*)(p->polynomial + i * p->rinfo->size));
        }
    }
}

void output_complex(Polynomial* p){
    if (!p->polynomial){
        printf("Polynomial is empty\n");
    }

    for (int i = p->n - 1; i >= 0; i--){
        if (i != 0){
            printf("(%.1f + i * %.1f) * x ^ %d + ", ((Complex*)(p->polynomial + i * p->rinfo->size))->Re, ((Complex*)(p->polynomial + i * p->rinfo->size))->Im, i);
        }
        else{
            printf("%.1f + i * %.1f\n", ((Complex*)(p->polynomial + i * p->rinfo->size))->Re, ((Complex*)(p->polynomial + i * p->rinfo->size))->Im);
        }
    }
}

Polynomial* input_int(Polynomial* p){
    if (p->polynomial){
        free(p->polynomial);
    }
    printf("Enter the polynomial degree: ");
    scanf("%d", &(p->n));

    p->n++;
    srand(time(NULL));

    p->polynomial = calloc(p->n, p->rinfo->size);

    for(int i = 0; i < p->n; i++){
        *((int*)(p->polynomial + i * p->rinfo->size)) = rand() % 100;
    }

    return p;
}

Polynomial* input_complex(Polynomial* p){
    if (p->polynomial){
        free(p->polynomial);
    }
    printf("Enter the polynomial degree: ");
    scanf("%d", &(p->n));

    p->n++;
    srand(time(NULL));

    p->polynomial = calloc(p->n, p->rinfo->size);

    for(int i = 0; i < p->n; i++){
        ((Complex*)(p->polynomial + i * p->rinfo->size))->Re = (rand() % 1000) / 10.0;
        ((Complex*)(p->polynomial + i * p->rinfo->size))->Im = (rand() % 1000) / 10.0;
    }

    return p;
}