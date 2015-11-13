//
//  main.c
//  omp_get_active_level
//
//  Created by Josué Carlos García Puig on 09/11/15.
//  Copyright © 2015 Josue Garcia. All rights reserved.
//

/*
 omp_get_active_level obtiene el nivel en el cual esta trabajando cierto proceso
 En este ejemplo se tiene un nivel anidado con ciertos procesos y se obtiene el nivel 
*/

#include <stdio.h>
#include <omp.h>

int main(int argc, const char * argv[]) {
    
    omp_set_nested(1);
    int i;
    
#pragma omp parallel num_threads(4)
    {
        printf("Trabaja el thread %d en el nivel %d\n",omp_get_thread_num(),omp_get_active_level());
        #pragma omp parallel num_threads(2)
        {
            printf("Trabaja el thread %d en el nivel %d\n",omp_get_thread_num(),omp_get_active_level());
        }
    }
    
    return 0;
}
