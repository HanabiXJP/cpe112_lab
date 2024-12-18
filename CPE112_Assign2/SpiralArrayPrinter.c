//PHANTHACH JIAMJARUSCHOT 66070501038
#include <stdio.h>
#include <stdlib.h>

void spiral(int **matrix, int rows, int cols) {
    int direction = 0;
    int top = 0;
    int down = rows-1;
    int left = 0;
    int right = cols-1; 

    while (top <= down && left <= right) {

        if(direction == 0) {
            for (int j = left ; j <= right ; j++) {
                printf("%d ", matrix[top][j]);
            }
            top += 1;
        }
        else if(direction == 1) {
            for (int i = top ; i <= down ; i++) {
                printf("%d ", matrix[i][right]);
            }
            right -= 1;
        }
        else if(direction == 2) {
            for (int j = right ; j >= left ; j--) {
                printf("%d ", matrix[down][j]);
            }
            down -= 1;
        }
        else if(direction == 3) {
            for (int i = down ; i >= top ; i--) {
                printf("%d ", matrix[i][left]);
            }
            left += 1;
        }

        direction = (direction + 1) % 4;

    }

}

int main() {
    int rows,cols;

    scanf("%d %d", &rows, &cols);

    int **matrix = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows ; i++) {
        matrix[i] = (int*)malloc(cols * sizeof(int));
    }

    for (int i = 0 ; i < rows ; i++) {
        for (int j = 0; j < cols ; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    spiral(matrix, rows, cols);
    //free the allocated memory
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }

    free(matrix);

    return 0;
}