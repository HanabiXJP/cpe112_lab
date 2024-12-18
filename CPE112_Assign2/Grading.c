//PHANTHACH JIAMJARUSCHOT 66070501038
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct {

char name[100];
float score[100];

}student;

void meancal (student *stud, int size, float *mean, float *sum) {
    for (int i = 0; i < size ; i++) {
        *sum += *stud[i].score;
    }

    *mean = (*sum/size);

    printf("%.2f ", *mean);
}

void SDcal (student *stud, int size, float *SD, float *sum, float mean) {
    for (int i = 0; i < size ; i++) {
        *sum += pow(*stud[i].score - mean, 2);
    }

    *SD = sqrt(*sum/size);
    printf("%.2f ", *SD);
}

void findminmax(student *stud, int size) {

    char maxname[100];
    char minname[100];
    float max = 0.00;
    float min = 100.00;
    for (int i = 0 ; i < size ; i++) {
        if (max < *stud[i].score){
            max = *stud[i].score;
            strcpy(maxname, stud[i].name);
        }
    }

    for (int i = 0 ; i < size ; i++) {
        if (min > *stud[i].score){
            min = *stud[i].score;
            strcpy(minname, stud[i].name);
        }
    }

    printf("%s %s", maxname, minname);
}

int main() {
    int size;
    float sum, mean, SD;
    sum = 0.0;
    scanf("%d", &size);
    student *stud = (student*)malloc(size * sizeof(student));

    for (int i = 0 ; i < size ; i++) {
        scanf("%s %f", stud[i].name, stud[i].score);
    }

    meancal (stud, size, &mean, &sum);
    sum = 0.0;
    SDcal (stud, size, &SD, &sum ,mean);
    findminmax(stud, size);
    free(stud);
    return 0;
}