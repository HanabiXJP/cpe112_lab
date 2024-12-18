//PHANTHACH JIAMJARUSCHOT 66070501038
#include <stdio.h>
#include <stdlib.h>

void process (int *sequence, int *size, int *start, int *end, int *step) {

    if (*start < 0) {
        *start = *start + *size;
        if(*start < 0) {
            *start = 0;
        }
    }

    if (*end < 0) {
        *end = *end + *size;
        if (*end < 0) {
            *end = 0;
        }
    }

    if (*start > *size) {
        *start = *size-1;
    }

    if (*end > *size) {
        *end = *size;
    }

}

int main () {
    int size, start, end, step, empty;
    empty = 0;
    scanf("%d", &size);

    int *sequence = (int*)malloc(size * sizeof(int));

    for (int i = 0 ; i < size ; i++) {
        scanf("%d", &sequence[i]);
    }

    scanf("%d %d %d", &start, &end, &step);

    process(sequence, &size, &start, &end, &step);

    if (step > 0) {
        for(int i = start ; i < end ; i += step) {
        printf("%d ", sequence[i]);
        empty++;
        }
    }
    else if (step < 0) {
        for(int i = start ; i > end ; i += step) {
        printf("%d ", sequence[i]);
        empty++;
        }
    }
    if(empty == 0) {
        printf("empty");
    }

    free(sequence);
    return 0;
}