//PHANTHACH JIAMJARUSCHOT 66070501038
#include <stdio.h>
#include <stdlib.h>

int main() {
    //INPUT
    int rows, cols, primary = 0, secondary = 0;
    scanf("%d %d", &rows, &cols);

    if(rows != cols) {// rows & columns checking
            printf("ERROR");
            exit(0);
        }

    int **matrix = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
    matrix[i] = (int *)malloc(cols * sizeof(int));
    }

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    for (int i = 0; i < rows && i < cols; i++) {
    primary += matrix[i][i];
    }
    for (int i = 0; i < rows && i < cols; i++) {
    secondary += matrix[i][cols - i - 1];
    }

    //OUTPUT
    printf("Primary: %d", primary);
    printf("\n");
    printf("Secondary: %d", secondary);

    free(matrix);
    return 0;
}

