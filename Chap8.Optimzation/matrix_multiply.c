#include <stdio.h>

version_ijk(int A[][10], int B[][10], int C[][10]) {
    int i, j, k, sum;
    int n = 10;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            sum = 0;
            for (k = 0; k < n; k++)
                sum += A[i][k] * B[k][j];
            C[i][j] += sum;
        }
    }
}

version_jik(int A[][10], int B[][10], int C[][10]) {
    int i, j, k, sum;
    int n = 10;
    for (j = 0; j < n; j++) {
        for (i = 0; i < n; i++) {
            sum = 0;
            for (k = 0; k < n; k++)
                sum += A[i][k] * B[k][j];
            C[i][j] += sum;
        }
    }
}

version_jki(int A[][10], int B[][10], int C[][10]) {
    int i, j, k, r;
    int n = 10;
    for (j = 0; j < n; j++) {
        for (k = 0; k < n; k++) {
            r = B[k][j];
            for (i = 0; i < n; i++)
                C[i][j] += A[i][k] * r;
        }
    }
}

version_kji(int A[][10], int B[][10], int C[][10]) {
    int i, j, k, r;
    int n = 10;
    for (k = 0; k < n; k++) {
        for (j = 0; j < n; j++) {
            r = B[k][j];
            for (i = 0; i < n; i++)
                C[i][j] += A[i][k] * r;
        }
    }
}

version_kij(int A[][10], int B[][10], int C[][10]) {
    int i, j, k, r;
    int n = 10;
    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            r = A[i][k];
            for (j = 0; j < n; j++)
                C[i][j] += r * B[k][j];
        }
    }
}

version_ikj(int A[][10], int B[][10], int C[][10]) {
    int i, j, k, r;
    int n = 10;
    for (i = 0; i < n; i++) {
        for (k = 0; k < n; k++) {
            r = A[i][k];
            for (j = 0; j < n; j++)
                C[i][j] += r * B[k][j];
        }
    }
}