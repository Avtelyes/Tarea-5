//
//  main.c
//  omp_get_num_devices
//
//  Created by Josué Carlos García Puig on 11/11/15.
//  Copyright © 2015 Josue Garcia. All rights reserved.
//

#include <stdio.h>
#include <omp.h>

int main(int argc, const char * argv[]) {
    
    const int dev = omp_get_num_devices();
    
    #pragma omp parallel num_threads(dev + 1)
    {
        tid = omp_get_thread_num();
        #pragma omp target data device( tid )
        {
            printf("Hola\n");
        }
    }
    
    return 0;
}
