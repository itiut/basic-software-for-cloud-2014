#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

double getCurrentTime() {
    struct timeval tp;
    gettimeofday(&tp, NULL);
    return tp.tv_sec + tp.tv_usec * 1.0E-6;
}

int **array_new(int n) {
    int **array = (int **) malloc(sizeof(int *) * n);
    for (int i = 0; i < n; i++) {
        array[i] = (int *) malloc(sizeof(int) * n);
    }
    return array;
}

void array_delete(int **array, int n) {
    for (int i = 0; i < n; i++) {
        free(array[i]);
    }
    free(array);
}

void compute(int **in, int **out, int n) {
    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < n - 1; j++) {
            out[i][j] =
                in[i-1][j-1] + in[i-1][j] + in[i-1][j+1] +
                in[i  ][j-1] + in[i  ][j] + in[i  ][j+1] +
                in[i+1][j-1] + in[i+1][j] + in[i+1][j+1];
        }
    }

}

int main(int argc, char *argv[]) {
    int try = 10;
    int n = 10000;
    if (argc > 1) {
        try = atoi(argv[1]);
    }
    if (argc > 2) {
        n = atoi(argv[2]);
    }

    for (int i = 0; i < try; i++) {
        double t0 = getCurrentTime();
        int **in = array_new(n);
        int **out = array_new(n);
        double t1 = getCurrentTime();
        compute(in, out, n);
        double t2 = getCurrentTime();
        printf("%2d %f %f\n", i + 1, t1 - t0, t2 - t1);
        array_delete(in, n);
        array_delete(out, n);
    }
    return 0;
}
