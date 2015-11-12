//
//  main.c
//  omp_get_team_size
//
//  Created by Josué Carlos García Puig on 09/11/15.
//  Copyright © 2015 Josue Garcia. All rights reserved.
//

#include <stdio.h>
#include <omp.h>

int main(int argc, const char * argv[]) {
    
    omp_set_nested(1);
    int i;
    
#pragma omp parallel num_threads(4)
    {
        int tid = omp_get_thread_num();
        printf("Trabaja el thread %d de un grupo de %d threads\n",tid,omp_get_team_size(1));
    }
    
    return 0;
}
