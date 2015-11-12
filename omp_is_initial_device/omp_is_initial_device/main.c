//
//  main.c
//  omp_is_initial_device
//
//  Created by Josué Carlos García Puig on 12/11/15.
//  Copyright © 2015 Josue Garcia. All rights reserved.
//

#include <stdlib.h>
#include <omp.h>
#include <stdio.h>


int main(int argc, const char * argv[]) {
    
    int a = 100;
    int b = 0;
    int c, d;
    
    omp_set_default_device(4);
    
    #pragma task
    #pragma omp target
    {
        c = omp_is_initial_device();
        
        printf("%d\n", c);
    }
    
    
    /* Create device buffers for a, b, c and transfer data from Host -> Device for a,b */
    /*#pragma omp target data map(to:a[0:size], b[0:size]) map(from:c[0:size])
    {
        printf("Estoy corriendo en el host: %d\n",omp_is_initial_device());
        #pragma omp target
        {
            printf("Estoy corriendo en el host: %d\n",omp_is_initial_device());
            int i;
            #pragma omp parallel for
            for (i = 0; i < 3; i++)
                c[i] += i + 4;
        }
    }*/ /* Device -> Host data transfer of buffer c is done here*/
    
    return 0;
}
