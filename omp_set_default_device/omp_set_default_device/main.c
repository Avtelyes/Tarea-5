//
//  main.c
//  omp_set_default_device
//
//  Created by Josué Carlos García Puig on 10/11/15.
//  Copyright © 2015 Josue Garcia. All rights reserved.
//

/*
 omp_set_default_device define devices para regiones de target
 En este ejemplo se definen dos regiones target y dentro de una se define los devices, la cual no afectará a la otra región
*/

#include <stdio.h>
#include <omp.h>

int main(int argc, const char * argv[]) {
    
    int i, fn=0;
    
    #pragma omp target
    #pragma omp parallel
    {
        omp_set_default_device(4);
        printf("Esta region paralela tiene 4 devices\n");
    }
    
    #pragma omp target
    #pragma omp parallel
    {
        printf("Esta region paralela no cuenta con devices\n");
    }
    
    return 0;
}
