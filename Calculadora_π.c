#include <stdio.h>
#include <pthread.h>

#define quantidade_de_threads 4


double sum = 0.0;
int n = 1000;
int thread_count = quantidade_de_threads ;

void *Thread_sum(void *rank) {
    long my_rank = (long) rank;
    double factor;
    long long i;
    long long my_n = n/thread_count;
    long long my_first_i = my_n * my_rank;
    long long my_last_i = my_first_i + my_n;
    if (my_first_i == 0) {
        factor = 1.0;
    } else {
        factor = -1.0;
    }
    for (i = my_first_i; i < my_last_i; i++, factor = -factor) {
        
        sum += factor / (2.0 * i + 1.0);
    }
    printf("thread %li valor de pi :%f \n",my_rank,sum*4);
    return NULL;
}

int main() {
    pthread_t threads[quantidade_de_threads ];
    long i;
    for (i = 0; i < thread_count; i++) {
        pthread_create(&threads[i], NULL, Thread_sum, (void *) i);
    }
    for (i = 0; i < thread_count; i++) {
        pthread_join(threads[i], NULL);
    }
    double pi =   4*sum;
    printf("Pi aproximado com N  %d : %.10f\n", n, pi);
    return 0;
}
