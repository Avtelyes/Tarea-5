//
//  main.c
//  omp_get_num_devices
//
//  Created by Josué Carlos García Puig on 11/11/15.
//  Copyright © 2015 Josue Garcia. All rights reserved.
//

/*
 omp_get_num_devices obtiene el numero de los target devices que hay
 En este ejemplo se obtiene el numero de devices y se crean threads a partir de ellos para que trabajen
*/

#include <stdio.h>
#include <omp.h>

int main(int argc, const char * argv[]) {
    
    const int dev = omp_get_num_devices();
    
    #pragma omp parallel num_threads(dev + 1)
    {
        int tid = omp_get_thread_num();
        #pragma omp target data device( tid )
        {
            printf("Soy el thread %d procesando informacion...\n",tid);
        }
    }
    
    return 0;
}
