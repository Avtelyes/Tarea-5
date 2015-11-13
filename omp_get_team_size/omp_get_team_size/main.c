//
//  main.c
//  omp_get_team_size
//
//  Created by Josué Carlos García Puig on 09/11/15.
//  Copyright © 2015 Josue Garcia. All rights reserved.
//

/*
 omp_get_team_size obtiene el numero de procesos que estan en una region paralela
 En este ejemplo se obtiene que proceso esta trabajando de un cierto total
*/

#include <stdio.h>
#include <omp.h>

void proceso();

int main(int argc, const char * argv[]) {
    
    omp_set_nested(1);
    int i;
    
#pragma omp parallel num_threads(4)
    {
        int tid = omp_get_thread_num();
        proceso();
        printf("Trabaja el thread %d de un grupo de %d threads\n",tid,omp_get_team_size(1));
    }
    
    return 0;
}

void proceso()
{
    printf("Estoy procesando un pedido...\n");
}
