#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_THREADS 4

int m = 4; // número de linhas da matriz A
int n = 4; // número de colunas da matriz A (e elementos do vetor x)
int A[4][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}}; // matriz A
int x[4] = {1, 2, 3, 4}; // vetor x
int y[4]; // vetor resultante

int thread_count = 4;

void *pth_mat_vect(void* rank){
    long my_rank = (long) rank;
    int i,j;
    int local_m= m/thread_count;
    int my_first_row = my_rank * local_m;
    int my_last_row = (my_rank+1)*local_m -1;
    for(i= my_first_row; i<= my_last_row; i++){
        y[i]= 0.0;
        for(j=0;j<n;j++){
            y[i] += A[i][j]*x[j];
        }
    }
    return NULL;
}

int main() {
    pthread_t thread_handles[MAX_THREADS];
    long thread;
    for (thread = 0; thread < thread_count; thread++) {
        pthread_create(&thread_handles[thread], NULL, pth_mat_vect, (void*) thread);
    }
    for (thread = 0; thread < thread_count; thread++) {
        pthread_join(thread_handles[thread], NULL);
    }

    for (int i = 0; i < m; i++) {
        printf("y[%d] = %d\n", i, y[i]);
    }

    return 0;
}
