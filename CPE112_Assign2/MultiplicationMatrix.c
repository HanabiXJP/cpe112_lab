//PHANTHACH JIAMJARUSCHOT 66070501038
#include <stdio.h>
#include <stdlib.h>


void multiply(int **matrixA, int **matrixB,int **matrixAB, int rowsA, int colsA, int rowsB, int colsB) {
    if (colsB != rowsA || colsA != rowsB) {
        printf("Not Compatible");
        return;
    }

    for (int i = 0; i < rowsA ; i++) {
        for (int j = 0; j < colsB ; j++) {
            matrixAB[i][j] = 0;
            for (int k = 0; k < colsA ; k++) {
                matrixAB[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }

    for (int i = 0; i < rowsA ; i++) {
        for (int j = 0; j < colsB ; j++) {
            printf("%d ", matrixAB[i][j]);
        }
        printf("\n");
    }
}
int main() {
    int rowsA, colsA, rowsB, colsB;
    scanf("%d %d", &rowsA, &colsA);

    int **matrixA = (int**)malloc(rowsA * sizeof(int*));
    for (int i = 0; i < rowsA ; i++) {
        matrixA[i] = (int*)malloc(colsA * sizeof(int));
    }

    for (int i = 0; i < rowsA ; i++) {
        for (int j = 0; j < colsA ; j++) {
            scanf("%d", &matrixA[i][j]);
        }
    }

    scanf("%d %d", &rowsB, &colsB);

    int **matrixB = (int**)malloc(rowsB * sizeof(int*));
    for (int i = 0; i < rowsB ; i++) {
        matrixB[i] = (int*)malloc(colsB * sizeof(int));
    }

    for (int i = 0; i < rowsB ; i++) {
        for (int j = 0; j < colsB ; j++) {
            scanf("%d", &matrixB[i][j]);
        }
    }

    int **matrixAB = (int**)malloc(rowsA * sizeof(int*));
    for (int i = 0; i < rowsA ; i++) {
        matrixAB[i] = (int*)malloc(colsB * sizeof(int)); 
    }

    multiply(matrixA, matrixB, matrixAB, rowsA, colsA, rowsB, colsB);

    for (int i = 0; i < rowsA; i++) {
        free(matrixA[i]);
    }

    for (int i = 0; i < rowsA; i++) {
        free(matrixB[i]);
    }

    for (int i = 0; i < rowsA; i++) {
        free(matrixAB[i]);
    }

    free(matrixA);
    free(matrixB);
    free(matrixAB);
    return 0;
}