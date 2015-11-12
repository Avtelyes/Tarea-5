//
//  main.c
//  omp_get_ancestor_thread_num
//
//  Created by Josué Carlos García Puig on 07/11/15.
//  Copyright © 2015 Josue Garcia. All rights reserved.
//

#include <stdio.h>
#include <omp.h>

int main(int argc, const char * argv[]) {
    
    omp_set_nested(1);
    int i;
    
    #pragma omp parallel num_threads(4)
    {
        #pragma omp parallel for num_threads(4)
        for (i=0; i<16; i++)
            printf("Task 1: thread %d children of %d\n",omp_get_thread_num(),
                   omp_get_ancestor_thread_num(1));
    }
    
    return 0;
}
