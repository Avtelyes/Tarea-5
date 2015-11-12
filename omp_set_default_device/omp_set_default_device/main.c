//
//  main.c
//  omp_set_default_device
//
//  Created by Josué Carlos García Puig on 10/11/15.
//  Copyright © 2015 Josue Garcia. All rights reserved.
//

#include <stdio.h>
#include <omp.h>

int main(int argc, const char * argv[]) {
    
    int i, fn=0;
    
    
    
    //printf("Default es: %d\n",omp_get_default_device());
    
    #pragma omp parallel
    {
        omp_set_default_device(4);
        printf("Esta region paralela tiene 4 devices\n");
        //printf("Default es: %d\n",omp_get_default_device());
    }
    
    #pragma omp parallel
    {
        printf("Esta region paralela no cuenta con devices\n");
        //printf("Default es: %d\n",omp_get_default_device());
    }
    
    return 0;
}
