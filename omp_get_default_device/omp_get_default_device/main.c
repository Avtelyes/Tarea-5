//
//  main.c
//  omp_get_default_device
//
//  Created by Josué Carlos García Puig on 11/11/15.
//  Copyright © 2015 Josue Garcia. All rights reserved.
//

/*
 omp_get_default_device obtiene los default devices que pueda contener una región de target
 En este ejemplo se definen dos regiones en la cual una se definen los default devices y en las dos se obtienen para ver como una no afecta a otra
*/

#include <stdio.h>
#include <omp.h>

int main(int argc, const char * argv[]) {
    
    int i, fn=0;
    
#pragma omp target
#pragma omp parallel
    {
        omp_set_default_device(4);
        printf("Soy el thread %d y esta region tiene: %d devices\n",omp_get_thread_num(),omp_get_default_device());
    }
    
#pragma omp target
#pragma omp parallel
    {
        printf("Soy el thread %d y esta region tiene: %d devices\n",omp_get_thread_num(),omp_get_default_device());
    }
    
    return 0;
}