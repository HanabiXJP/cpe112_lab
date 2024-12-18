//Phanthach Jiamjaruschot 66070501038
#include <stdio.h>

int main(){

    int num, i, newnum;
    int count = 0;

    scanf("%d", &num);
    int arr[num];
    int newarr[num];

    for (i = 0; i < num; i++) {
        scanf("%d", &arr[i]);
    }

    for (i = 0; i < num; i++) {

        if(arr[i] != arr[i+1]) {

            newarr[count] = arr[i];
            count++;

        }
    }

    printf("%d", count);

    printf("\n");

    for (i = 0; i < count; i++) {

        printf("%d ", newarr[i]);
        
    }
    
    return 0;
}