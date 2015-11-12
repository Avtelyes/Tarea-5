//
//  main.c
//  omp_get_default_device
//
//  Created by Josué Carlos García Puig on 11/11/15.
//  Copyright © 2015 Josue Garcia. All rights reserved.
//

#include <stdio.h>
#include <omp.h>

int main(int argc, const char * argv[]) {
    
    int i, fn=0;
    
    printf("Esta region tiene: %d devices\n",omp_get_default_device());
    
#pragma omp parallel
    {
        omp_set_default_device(4);
        printf("Esta region tiene: %d devices\n",omp_get_default_device());
    }
    
#pragma omp parallel
    {
        printf("Esta region tiene: %d devices\n",omp_get_default_device());
    }
    
    return 0;
}