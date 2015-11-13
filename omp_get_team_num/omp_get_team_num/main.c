//
//  main.c
//  omp_get_team_num
//
//  Created by Josué Carlos García Puig on 12/11/15.
//  Copyright © 2015 Josue Garcia. All rights reserved.
//

/*
 omp_get_team_num obtiene el numero de id del equipo que actualmente esta trabajando
 En este ejemplo se crean dos vectores con numeros aleatorios, se mapea un target con ellos y se define un numero N de equipos con un maximo nivel de threads. Después se calcula la suma del producto de los vectores por medio de una reduccion.
 */

#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 5
#define T 3


int main(int argc, const char * argv[]) {
    
    srand(time(NULL));
    
    double *v1 = ( double* ) malloc( N * sizeof(double));
    double *v2 = ( double* ) malloc( N * sizeof(double));
    double suma = 0;
    int i;
    
    for(i = 0; i < N; i++)
    {
        *(v1 + i) = ((double)(rand() % 100 + 1)) / 100;
        *(v2 + i) = ((double)(rand() % 100 + 1)) / 100;
    }
    
#pragma omp target map(to:v1[0:N],v2[0:N])
#pragma omp teams num_teams(N) thread_limit(T)
#pragma omp distribute parallel for reduction(+:suma)
    for(i=0;i<N;i++)
    {
        printf("iteración: %d, hay un total de %d equipos, el thread %d del equipo %d esta procesando...\n",
               i,omp_get_num_teams(),omp_get_thread_num(), omp_get_team_num());
        
        suma += *(v1 + i) * *(v2 + i);
    }
    
    printf("La suma es de: %f\n", suma);
    
    free(v1);
    free(v2);
    return 0;
}
