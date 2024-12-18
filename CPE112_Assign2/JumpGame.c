//PHANTHACH JIAMJARUSCHOT 66070501038
#include <stdio.h>
#include <stdlib.h>

int canJumps(int* index, int size) {

    int count = 0;

    if (size==1) { 
        printf("%d", count);
        return 1;

    }

    int max = 0;

    for (int i = 0; i < size && max >= i ; i++) {

        if(max < i + index[i]) {

            max = i + index[i];

            count++;
        }

        if(max >= size-1) {

            printf("%d", count);

            return 1;
        }
    }
    printf("Not Possible");
    return 0;

}
int main() {

    int size;

    scanf("%d", &size);

    int *index = (int*)malloc(size * sizeof(int));

    for (int i = 0; i < size ; i++) {
        scanf("%d", &index[i]);
    }

    canJumps(index, size);

    free(index);
    return 0;
}