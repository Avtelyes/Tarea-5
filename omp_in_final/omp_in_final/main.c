//
//  main.c
//  omp_in_final
//
//  Created by Josué Carlos García Puig on 09/11/15.
//  Copyright © 2015 Josue Garcia. All rights reserved.
//

#include <stdio.h>
#include <omp.h>

int main(int argc, const char * argv[]) {
    
    int i, fn=0;
    
    #pragma omp parallel num_threads(1)
    {
        
        #pragma omp for
            for(i=0; i<4; ++i)
            {
                #pragma omp task firstprivate(fn) final(fn == 3)
                {
                    if(omp_in_final())
                        printf("Estoy al final del task\n");
                    else
                        printf("Aun sigo en el task\n");
                }
                ++fn;
            }
    }
    
    return 0;
}
