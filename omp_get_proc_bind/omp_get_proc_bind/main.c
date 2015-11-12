//
//  main.c
//  omp_get_proc_bind
//
//  Created by Josué Carlos García Puig on 10/11/15.
//  Copyright © 2015 Josue Garcia. All rights reserved.
//

/*
    export OMP_PROC_BIND=true
    export OMP_PROC_BIND=false
*/

#include <stdio.h>
#include <omp.h>

int main(int argc, const char * argv[]) {
    
    int i, fn=0;
    
    #pragma omp parallel
    {
        printf("La policy es: %d\n",omp_get_proc_bind());
    }
    
    return 0;
}
