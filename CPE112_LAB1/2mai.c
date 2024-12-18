#include <stdio.h>
#include <stdlib.h>

int m, n, Uni_num, p, Anum, q, Bnum, SAnum, SBnum;

int SortAnum,SortBnum,SortSAnum,SortSBnum = 0;

int* UniArray(int* Uni_num);

int* A_Array(int* Anum);

int* B_Array(int* Bnum);

int* SA_Array(int* arrayA, int* arrayS, int* SAnum);

int IsASubset(int* arrayA, int* arrayS, int Anum, int Uni_num);

int* SB_Array(int* arrayB, int* arrayS, int* SBnum);

int IsBSubset(int* arrayB, int* arrayS, int Bnum, int Uni_num);

int main() {
    scanf("%d %d", &m, &n);
    scanf("%d", &p);

    int* arrayS = UniArray(&Uni_num);
    int* arrayA = A_Array(&Anum);

    scanf("%d", &q);
    int* arrayB = B_Array(&Bnum);

    // for (int i = 0; i < SortAnum; i++) {

    //     printf("%d ", arrayA[i]);

    // }
    // printf("\n");

    // for (int i = 0; i < SortBnum; i++) {

    //     printf("%d ", arrayB[i]);

    // }
    // printf("\n");

    if(IsASubset(arrayA, arrayS, SortAnum, Uni_num)) {

        int* arraySA = SA_Array(arrayA, arrayS, &SAnum);

        for (int i = 0; i < SortSAnum; i++) {

            printf("%d ", arraySA[i]);

        }
        free(arraySA);
        
    } else {
        printf("empty");
    }

    printf("\n");

    if(IsBSubset(arrayB, arrayS, SortBnum, Uni_num)) {

        int* arraySB = SB_Array(arrayB, arrayS, &SBnum);

        for (int i = 0; i < SortSBnum; i++) {

            printf("%d ", arraySB[i]);

        }
        free(arraySB);
    } else {
        printf("empty");
    }
    printf("\n");

    free(arrayS);
    free(arrayA);
    free(arrayB);

    return 0;
}

int* UniArray(int* Uni_num) {
    *Uni_num = n - m + 1;
    int* arrayS = (int*)malloc(*Uni_num * sizeof(int));

    for (int i = 0; i < *Uni_num; i++) {
        arrayS[i] = m++;
    }

    return arrayS;
}

int* A_Array(int* Anum) {
    *Anum = p;
    int* arrayA = (int*)malloc(p * sizeof(int));

    for (int i = 0; i < *Anum; i++) {
        scanf("%d", &arrayA[i]);
    }

    for (int i = 0; i < *Anum; i++) {
        if (i == 0 || arrayA[i] != arrayA[i - 1]) {
            arrayA[SortAnum++] = arrayA[i];
        }
    }

    return arrayA;
}

int* B_Array(int* Bnum) {
    *Bnum = q;
    int* arrayB = (int*)malloc(q * sizeof(int));

    for (int i = 0; i < *Bnum; i++) {
        scanf("%d", &arrayB[i]);
    }

    for (int i = 0; i < *Bnum; i++) {
        if (i == 0 || arrayB[i] != arrayB[i - 1]) {
            arrayB[SortBnum++] = arrayB[i];
        }
    }

    return arrayB;
}

int IsASubset(int* arrayA,int* arrayS, int Anum, int Uni_num) {
    for (int i = 0; i < Anum; i++) {
        int isAinS = 0; //this is mean no element of A in S

        for (int j = 0; j < Uni_num; j++) {
            if (arrayA[i] == arrayS[j]) {
                isAinS = 1;
                break;
            }
        }

        if(!isAinS) {
            return 0;
        }
    }

    return 1;
}

int* SA_Array(int* arrayA, int* arrayS, int* SAnum) {

    *SAnum = SortAnum;

    int* arraySA = (int*)malloc(SortAnum * sizeof(int));

    for(int i = 0; i < *SAnum; i++) {
        if(arrayA[i] == arrayS[i]){
            arraySA[SortSAnum++] = arrayA[i];
        }
    }

    return arraySA;
}

int IsBSubset(int* arrayB,int* arrayS, int Bnum, int Uni_num) {
    for (int i = 0; i < Bnum; i++) {
        int isBinS = 0; //this is mean no element of B in S

        for (int j = 0; j < Uni_num; j++) {
            if (arrayB[i] == arrayS[j]) {
                isBinS = 1;
                break;
            }
        }

        if(!isBinS) {
            return 0;
        }
    }

    return 1;
}

int* SB_Array(int* arrayB, int* arrayS, int* SBnum) {

    *SBnum = SortBnum;

    int* arraySB = (int*)malloc(SortBnum * sizeof(int));

    for(int i = 0; i < *SBnum; i++) {
        if(arrayB[i] == arrayS[i]){
            arraySB[SortSBnum++] = arrayB[i];
        }
    }

    return arraySB;
}

