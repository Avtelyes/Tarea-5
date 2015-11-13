//
//  main.c
//  omp_is_initial_device
//
//  Created by Josué Carlos García Puig on 12/11/15.
//  Copyright © 2015 Josue Garcia. All rights reserved.
//

/*
 omp_is_initial_device devuelve true si detecta que esta corriendo en el host o falso si en un device.
 En este ejemplo se declaran 3 arreglos de los cuales 2 se llenan de numeros aleatorios y en el tercero se guarda la suma de los otros. En el ultimo paso se detecta si los calculos se hacen en el host o en algun device
*/

#include <stdlib.h>
#include <omp.h>
#include <stdio.h>
#include <time.h>

#define N 20

int main(int argc, const char * argv[]) {
    
    srand(time(NULL));
    
    int *a = ( int * ) malloc( N * sizeof(int));
    int *b = ( int * ) malloc( N * sizeof(int));
    int *c = ( int * ) malloc( N * sizeof(int));
    
    int size = N + 10;
    int suma = 0;
    int i;
    
    for(i = 0; i < N; ++i)
    {
        *(a + i) = rand() % 59 + 1;
        *(b + i) = rand() % 39 + 1;
    }
    
    #pragma omp target data map(to:a[0:size], b[0:size]) map(from:c[0:size])
    {
        #pragma omp target
        {
            if(omp_is_initial_device())
                printf("Estoy procesando en el host...\n");
            else
                printf("Estoy procesando en el device...\n");
            #pragma omp parallel for
            for (i = 0; i < N; ++i)
            {
                *(c + i) = *(a + i) + *(b + i);
                suma += *(c +i);
            }
        }
    }

    
    printf("La operacion ha terminado, la suma es de: %d\n", suma);
    
    free(a);
    free(b);
    free(c);
    
    return 0;
}
