//Phanthach Jiamjaruschot 66070501038
#include <stdio.h>
#include <stdlib.h>

int *ArrayS(int start, int size) {
    int i;
    int *set = (int*)malloc(size * sizeof(int));
    for (i = 0; i < size ; i++) {
        set[i] = start + i;
    }
    return set;
}

int *Arraytrans(int *arr, int *size) {
    int i,j,k;
    for (i = 0; i < (*size); i++) {
        for (j = i + 1; j < (*size); j++) {
            if (arr[i] == arr[j]) {
                for (k = j; k < (*size); k++) {
                    arr[k] = arr[k + 1];
                }
                (*size)--;
                j--;
            }
        }
    }
    int *set = (int*)malloc((*size) * sizeof(int));
    for (i = 0; i < *size; i++) {
        set[i] = arr[i];
    }

    return set;
}

int *SortSet(int *set, int *size)
{
    int i, j, k;
    for (i = 0; i < *size; i++)
    {
        for (j = i + 1; j < *size; j++)
        {
            if (set[i] > set[j])
            {
                int temp = set[i];
                set[i] = set[j];
                set[j] = temp;
            }
        }
    }

    return set;
}


int *select_in_range(int *set, int *size, int start, int end) {
    int i, j;
    for (i = 0; i < *size; i++)
    {
        if (set[i] < start || set[i] > end)
        {
            for (j = i; j < *size; j++)
            {
                set[j] = set[j + 1];
            }
            (*size)--;
            i--;
        }
    }
    return set;
}

void displaySet(int *arr, int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    if (size == 0) {
        printf("empty");
    }
    printf("\n");
}

int *unionfunction(int *setA, int *setB, int *sizeA, int *sizeB, int *UnionSize) {
    int i,j,k;
    int *UnionSet = (int*)malloc((*UnionSize) * sizeof(int));
    for (i = 0; i < *sizeA; i++)
    {
        UnionSet[i] = setA[i];
    }
    for (j = 0; j < *sizeB; j++)
    {
        UnionSet[i + j] = setB[j];
    }
    UnionSet = Arraytrans(UnionSet, UnionSize);
    UnionSet = SortSet(UnionSet, UnionSize);

    return UnionSet;
}

int *intersectionfunction(int *setA, int *setB, int *Asize, int *Bsize, int *IntersectionSize){
    int i, j, k;
    int *IntersectionSet = (int *)malloc((*IntersectionSize) * sizeof(int));
    int num_intersection = 0;
    for (i = 0; i < *Asize; i++)
    {
        for (j = 0; j < *Bsize; j++)
        {
            if (setA[i] == setB[j])
            {
                IntersectionSet[i] = setA[i];
                num_intersection++;
                (*IntersectionSize)--;
            }
        }
    }
    (*IntersectionSize) -= ((*Bsize) - num_intersection) + ((*Asize) - num_intersection);
    IntersectionSet = Arraytrans(IntersectionSet, IntersectionSize);
    IntersectionSet = SortSet(IntersectionSet, IntersectionSize);

    return IntersectionSet;
}

int *differencefunction(int *setA, int *setB, int *Asize, int *Bsize, int *DifferenceSize){
    int i, j, k;
    int *DifferenceSet = (int *)malloc((*DifferenceSize) * sizeof(int));
    for (i = 0; i < *Asize; i++) {
        DifferenceSet[i] = setA[i];
    }
    for (i = 0; i < *Asize; i++) {
        for (j = 0; j < *Bsize; j++) {
            if (DifferenceSet[i] == setB[j]) {
                for (k = i; k < *Asize; k++) {
                    DifferenceSet[k] = DifferenceSet[k + 1];
                }
                (*DifferenceSize)--;
            }
        }
    }
    DifferenceSet = Arraytrans(DifferenceSet, DifferenceSize);
    DifferenceSet = SortSet(DifferenceSet, DifferenceSize);

    return DifferenceSet;
}

int *complementfunction(int *set, int *size, int *UnionSet, int *UnionSize, int *ComplementSize){
    int i, j, k;
    int *ComplementSet = (int *)malloc((*UnionSize) * sizeof(int));
    for (i = 0; i < *UnionSize; i++)
    {
        ComplementSet[i] = UnionSet[i];
    }
    
    for (i = 0; i < *size; i++)
    {
        for (j = 0; j < *UnionSize; j++)
        {
            if (set[i] == ComplementSet[j])
            {
                for (k = j; k < *UnionSize; k++)
                {
                    ComplementSet[k] = ComplementSet[k + 1];
                }
            }
        }
    }

    ComplementSet = Arraytrans(ComplementSet, ComplementSize);
    ComplementSet = SortSet(ComplementSet, ComplementSize);

    return ComplementSet;
}



int main() {

    int m, n, Asize, Bsize;

    //---------Input---------//
    scanf("%d %d", &m, &n); //create universal set
    int *SetU = ArrayS(m,((n-m) + 1)); //create universal set in range from m to n

    scanf("%d", &Asize);//input set A
    int *arrayA = (int*)malloc(Asize * sizeof(int));
    for (int i = 0; i < Asize; i++) {
        scanf("%d", &arrayA[i]);
    }
    int *setA = Arraytrans(arrayA, &Asize); //change array to set
    setA = select_in_range(setA, &Asize, m, n); //select set that in range

    scanf("%d", &Bsize);//input set B
    int *arrayB = (int*)malloc(Bsize * sizeof(int));
    for (int i = 0; i < Bsize; i++) {
        scanf("%d", &arrayB[i]);
    }
    int *setB = Arraytrans(arrayB, &Bsize); //change array to set
    setB = select_in_range(setB, &Bsize, m, n); //select set that in range

     //---------Output---------//

     // Show set SA
     displaySet(setA, Asize);

     // Show set SB
     displaySet(setB, Bsize);

     // Union set SA & SB
     int UnionSize = Asize + Bsize;
     int * UnionSet = unionfunction(setA, setB, &Asize, &Bsize, &UnionSize);
     displaySet(UnionSet, UnionSize);

     // Intersection set SA & SB
    int IntersectionSize = Asize + Bsize;
    int *IntersectionSet = intersectionfunction(setA, setB, &Asize, &Bsize, &IntersectionSize);
    displaySet(IntersectionSet, IntersectionSize);

    // set SA - SB
    int DifferenceSize = Asize;
    int *DifferenceSet = differencefunction(setA, setB, &Asize, &Bsize, &DifferenceSize);
    displaySet(DifferenceSet, DifferenceSize);

    // set SB - SA
    DifferenceSize = Bsize;
    DifferenceSet = differencefunction(setB, setA, &Bsize, &Asize, &DifferenceSize);
    displaySet(DifferenceSet, DifferenceSize);

    // Complement of SA
    int ComplementSize = ((n - m) + 1) - Asize;
    int UniSize = ((n - m) + 1);
    int *ComplementSet = complementfunction(setA, &Asize, SetU, &UniSize, &ComplementSize);
    displaySet(ComplementSet, ComplementSize);

    // Complement of SB
    ComplementSize = ((n - m) + 1) - Bsize;
    ComplementSet = complementfunction(setB, &Bsize, SetU, &UniSize, &ComplementSize);
    displaySet(ComplementSet, ComplementSize);

     free(arrayA);
     free(arrayB);
     free(setA);
     free(setB);
     free(UnionSet);
     free(IntersectionSet);
     free(DifferenceSet);
     free(ComplementSet);
     free(SetU);

    return 0;
}