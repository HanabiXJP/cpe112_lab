//PHANTHACH JIAMJARUSCHOT 66070501038
#include <stdio.h>
#include <stdlib.h>

void LargestSort(int *Array ,int n) {
    int max = 0;
    int maxindex;

    for(int i = 0; i < n ; i++) {
        if (max < *(Array + i)) {
            max = *(Array + i);
            maxindex = i;
        }
    }

    printf("%d %d", max, maxindex);
    printf("\n");

}

void SmallestSort(int *Array ,int n) {
    int min = 10000;
    int minindex;

    for(int i = 0; i < n ; i++) {
        if (min > *(Array + i)) {
            min = *(Array + i);
            minindex = i;
        }
    }

    printf("%d %d", min, minindex);

}

int main() {

    //INPUT
    int n;

    scanf("%d", &n);

    int *Array = (int*)malloc(n * sizeof(int));

    for (int i = 0 ; i < n ; i++) {
        scanf("%d", (Array + i));
    }

    //OUTPUT

    LargestSort(Array, n);
    SmallestSort(Array, n);

    return 0;
}