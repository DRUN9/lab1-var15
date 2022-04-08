#include <stdio.h>
#include "head.h"

void int_menu(){
    Polynomial* p1 = initialize();
    Polynomial* p2 = initialize();
    Polynomial* res = initialize();

    p1->rinfo = create_rinfo(sizeof(int), add_int, mult_int);
    p2->rinfo = create_rinfo(sizeof(int), add_int, mult_int);
    res->rinfo = create_rinfo(sizeof(int), add_int, mult_int);

    int k0, k1, k2, scalar, val, x;

    k0 = 1;
    while(k0){
        k1 = 0;
        printf("Choose option:\n1. Input\n2. Output\n3. Operations\n4. Exit\n");
        scanf("%d", &k1);

        switch(k1){
            case 1:
                p1 = input_int(p1);
                p2 = input_int(p2);
                break;

            case 2:
                printf("1st polynomial:\n");
                output_int(p1);
                printf("2nd polynomial:\n");
                output_int(p2);
                printf("result polynomial:\n");
                output_int(res);
                break;
            
            case 3:
                printf("Choose option:\n1. Addition\n2. Multitplication\n3. Multiplication by a scalar\n4. Calculate the value\n");
                scanf("%d", &k2);
                switch(k2){
                    case 1:
                        sum(p1, p2, res);
                        break;
                    
                    case 2:
                        mult(p1, p2, res);
                        break;
                    
                    case 3:
                        printf("Enter the scalar: ");
                        scanf("%d", &scalar);

                        mult_scalar(&scalar, res);
                        break;
                    
                    case 4:
                        printf("Enter the x: ");
                        scanf("%d", &x);
                        value(res, &x, &val);
                        printf("Value equals %d\n", val);
                        break;
                    default:
                        printf("Wrong option\n");
                }
                break;
            
            case 4:
                free(p1->rinfo);
                free(p2->rinfo);
                free(res->rinfo);
                free_poly(p1);
                free_poly(p2);
                free_poly(res);
                k0 = 0;
                break;
            
            default:
                printf("Wrong option\n");
        }
    }
}

void complex_menu(){
    Polynomial* p1 = initialize();
    Polynomial* p2 = initialize();
    Polynomial* res = initialize();

    p1->rinfo = create_rinfo(sizeof(Complex), add_complex, mult_complex);
    p2->rinfo = create_rinfo(sizeof(Complex), add_complex, mult_complex);
    res->rinfo = create_rinfo(sizeof(Complex), add_complex, mult_complex);

    int k0, k1, k2;

    Complex* scalar;
    Complex* val;
    Complex* x;

    k0 = 1;
    while(k0){
        k1 = 0;
        printf("Choose option:\n1. Input\n2. Output\n3. Operations\n4. Exit\n");
        scanf("%d", &k1);

        switch(k1){
            case 1:
                p1 = input_complex(p1);
                p2 = input_complex(p2);
                break;

            case 2:
                printf("1st polynomial:\n");
                output_complex(p1);
                printf("2nd polynomial:\n");
                output_complex(p2);
                printf("result polynomial:\n");
                output_complex(res);
                break;
            
            case 3:
                printf("Choose option:\n1. Addition\n2. Multitplication\n3. Multiplication by a scalar\n4. Calculate the value\n");
                scanf("%d", &k2);
                switch(k2){
                    case 1:
                        sum(p1, p2, res);
                        break;
                    
                    case 2:
                        mult(p1, p2, res);
                        break;
                    
                    case 3:
                        scalar = (Complex*)calloc(1, res->rinfo->size);
                        printf("Enter the scalar: ");
                        scanf("%f %f", &(scalar->Re), &(scalar->Im));

                        mult_scalar(scalar, res);
                        free(scalar);
                        break;
                    
                    case 4:
                        x = (Complex*)calloc(1, res->rinfo->size);
                        val = (Complex*)calloc(1, res->rinfo->size);
                        printf("Enter the x: ");
                        scanf("%f %f", &(x->Re), &(x->Im));
                        value(res, x, val);
                        printf("Value equals %.1f + i * %.1f\n", val->Re, val->Im);
                        free(x);
                        free(val);
                        break;
                    default:
                        printf("Wrong option\n");
                }
                break;
            
            case 4:
                free(p1->rinfo);
                free(p2->rinfo);
                free(res->rinfo);
                free_poly(p1);
                free_poly(p2);
                free_poly(res);
                k0 = 0;
                break;
            
            default:
                printf("Wrong option\n");
        }
    }
}

int main(){
    int k;
    printf("Choose the type of elements:\n1. Int\n2. Complex\n");
    scanf("%d", &k);
    if (k == 1){
        int_menu();
    }
    else{
        complex_menu();
    }
    return 0;
}