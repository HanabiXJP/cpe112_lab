#include <stdio.h>
#include <stdlib.h>

int main () {
    //INPUT
    int n, choice;
    scanf("%d", &n);
    int* array = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n ; i++) {
        scanf("%d", (array + i));
    }
    scanf("%d", &choice);

    //OUTPUT
    if (choice == 0) {
        for (int i = 0 ; i < n ; i+=2) {
            printf("%d ", *(array + i));
        }
    }

    else if (choice == 1 && n != 1) {
        for (int i = 1 ; i < n ; i+=2) {
            printf("%d ", *(array + i));
        }
    }

    else {
        printf("none");
    }


    free(array);
    return 0;
}
