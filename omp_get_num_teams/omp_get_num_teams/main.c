//
//  main.c
//  omp_get_num_teams
//
//  Created by Josué Carlos García Puig on 11/11/15.
//  Copyright © 2015 Josue Garcia. All rights reserved.
//

#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <sys/time.h>


/*int main()
{
    int N=20;
    double *v1=(double*)malloc(N*sizeof(double));
    double *v2=(double*)malloc(N*sizeof(double));
    double sum=0;
    int i,j;
    for(i = 0; i < N; i++)
    {
        v1[i]=((rand() % 100) + (((double )(rand() % 100)) / 100));
        v2[i]=((rand() % 100) + (((double )(rand() % 100)) / 100));
    }
#pragma omp target map(to:v1[0:N],v2[0:N])
#pragma omp teams num_teams(20) thread_limit(2)
#pragma omp distribute parallel for reduction(+:sum)
    for(i=0;i<N;i++)
    {
        printf("i=%d, num_teams=%d, team_id=%d, num_threads=%d, thread_id=%d\n",
               i,omp_get_num_teams(),omp_get_team_num(),omp_get_num_threads(),omp_get_thread_num());
        
        sum+=v1[i]*v2[i];
    }
    
    free(v1);
    free(v2);
    return 0;
}*/
/*int main()
{
    omp_set_nested(1);
#pragma omp target
    {
#pragma omp teams num_teams(60)
        {
            #pragma omp parallel
            {
                printf("Teams: %d, Target 1\n", omp_get_num_teams());
                #pragma omp teams num_teams(2)
                #pragma omp target
                {
                    #pragma omp parallel
                    {
                        printf("Teams: %d, Target 1\n", omp_get_num_teams());
                    }
                    printf("Teams: %d, Target 1\n", omp_get_num_teams());
                }
                #pragma omp parallel
                {
                    printf("Teams: %d, Target 1\n", omp_get_num_teams());
                }
            }
            #pragma omp parallel
            {
                printf("Teams: %d, Target 1\n", omp_get_num_teams());
            }
            
        }
    }
#pragma omp target
    {
#pragma omp teams num_teams(60)
        {
            printf("Teams: %d, Target 2\n", omp_get_team_num());
        }
    }
    return 0;
}*/

//#pragma omp declare target
//extern void get_offload_dev();
float dotprod(float B[], float C[], int N)
{
    float sum0 = 0.0;
    float sum1 = 0.0;
#pragma omp target map(to: B[:N], C[:N])
#pragma omp teams num_teams(2)
    {
        int i;
        
        printf("%d\n",omp_get_num_teams());
        if (omp_get_num_teams() != 2)
            abort();
        
        //get_offload_dev();
        
        if (omp_get_team_num() == 0)
        {
#pragma omp parallel for reduction(+:sum0)
            for (i=0; i<N/2; i++)
                sum0 += B[i] * C[i];
        }
        else if (omp_get_team_num() == 1)
        {
#pragma omp parallel for reduction(+:sum1)
            for (i=N/2; i<N; i++)
                sum1 += B[i] * C[i];
        }
    }
    return sum0 + sum1;
}

int main()
{
    float A[] = {2.4,46.7,24.7};
    float B[] = {2.4,46.7,24.7};
    
    float ans = dotprod(A, B, 3);
    
    return 0;
}
