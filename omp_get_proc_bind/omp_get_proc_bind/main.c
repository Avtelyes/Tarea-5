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
    proc_bind(master | close | spread)
 
    omp_get_proc_bind se utiliza para verificar si se tiene una politica de afinidad, se exporta una variable de ambiente OMP_PROC_BIND para activarla y despues en la region paralela se poen el tipo
 
    En este ejemplo una vez exportada la variable de ambiente detecta si el programa la usa o no
*/

#include <stdio.h>
#include <omp.h>

int main(int argc, const char * argv[]) {
    
    int i, fn=0;
    
    #pragma omp parallel proc_bind(master)
    {
        if(omp_get_proc_bind())
            printf("Soy el thread %d y estoy tabajando con una policy definida\n", omp_get_thread_num());
        else
            printf("Soy el thread %d y NO estoy tabajando con una policy definida\n", omp_get_thread_num());
    }
    
    return 0;
}
