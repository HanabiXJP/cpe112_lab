//66070501038 PHANTHACH JIAMJARUSCHOT
#include <stdio.h>

int Search(int array[], int size, int step) {
    int index = 0;
    while (size > 1) 
    {
        index = (index + step - 1) % size;

        for (int i = index; i < size - 1; i++) {
            array[i] = array[i + 1];
        }

        size--;
    }

    return array[0];
}

int main() {
    int size, step;

    scanf("%d %d", &size, &step);

    int array[size];

    for (int i = 0; i < size; ++i) {
        scanf("%d", &array[i]);
    }

    int linklist = Search(array, size, step);
    printf("%d\n", linklist);

    return 0;
}