//PHANTHACH JIAMJARUSCHOT 66070501038
#include <stdio.h>
#include <stdlib.h>

int main () {

    int rows, cols; 
    scanf("%d %d", &rows, &cols);

    int **matrix = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
    matrix[i] = (int *)malloc(cols * sizeof(int));
    }

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int **transpose = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
    transpose[i] = (int *)malloc(cols * sizeof(int));
    }

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            transpose[j][i] = matrix[i][j];
        }
    }

    int complete = rows*cols;
    int sym_state = 0;
    int skew_state = 0;

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            if (transpose[i][j] == matrix[i][j]) {
                sym_state++;
            }
        }
    }

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            if (transpose[i][j] == -(matrix[i][j]) ) {
                skew_state++;
                sym_state--;
            }
        }
    }

    if (sym_state == complete) {
        printf("The matrix is symmetric");
    }
    if (skew_state == complete) {
        printf("The matrix is skew-symmetric");
    }
    if (skew_state != complete && sym_state != complete) {
        printf("None");
    }


    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }

    for (int i = 0; i < rows; i++) {
        free(transpose[i]);
    }

    free(transpose);
    free(matrix);
    return 0;
}