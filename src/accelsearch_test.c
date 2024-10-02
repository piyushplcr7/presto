#include <stdio.h>
#include <omp.h>
#include <time.h>
#include <assert.h>

int main() {
    int fftlen = 4096;
    int numws = 31;
    double valarray[31]; 
    struct timespec starto, endo;
    assert(clock_gettime(CLOCK_MONOTONIC, &starto) == 0);

#ifdef _OPENMP
#pragma omp parallel default(none) shared(fftlen, numws,valarray)
#endif
    {
        struct timespec start_thread, end_thread;

#ifdef _OPENMP
#pragma omp for
#endif
        for (int ii = 0; ii < numws; ii++) {
            //clock_gettime(CLOCK_MONOTONIC, &start_thread);
            //int tid = omp_get_thread_num();
            double val = 0;
            
            for (int kk = 0; kk < fftlen * 2; kk += 2) {
                const float dr = (float) kk / 3000., di = (float) (kk + 1) / 3000.;
                const float kr = 0.3, ki = 0.1;
                val += dr * kr + di * ki;
                val += di * kr - dr * ki;
            }

            //clock_gettime(CLOCK_MONOTONIC, &end_thread);
            //double time_thread = (end_thread.tv_sec - start_thread.tv_sec) * 1e9 +
             //                    (end_thread.tv_nsec - start_thread.tv_nsec);

/* #pragma omp critical
            {
                printf("Thread: %d, ii = %d spent %f nanoseconds\n", tid, ii, time_thread);
            } */
           valarray[ii] = val;
        }
    }

    assert(clock_gettime(CLOCK_MONOTONIC, &endo) == 0);
    double cpu_time_used = (endo.tv_sec - starto.tv_sec) * 1e9 + 
                           (endo.tv_nsec - starto.tv_nsec);
    printf("#KALANINJA: OpenMP correlation %f nanoseconds\n", cpu_time_used);

    for (int i = 0 ; i < 31 ; ++i) {
        printf("valarray[i] = %f \n", valarray[i]);
    }

    return 0;
}