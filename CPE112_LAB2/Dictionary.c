//PHANTHACH JIAMJARUSCHOT 66070501038
#include<stdio.h>
#include<stdlib.h>
#include<string.h> //hint

typedef struct {

 char value[100];
 char key[100];

}dict; //New Data Type

void editdict(dict *dic, int size) { //for editing the dictionary
    char addvalue[100];
    char addkey[100];
    scanf("%s %s", addkey, addvalue);

    for (int i = 0 ; i < size ; i++) {
        if(strcmp(addkey,dic[i].key) == 0){ //0 is equal 1 is not equal
            strcpy(dic[i].value, addvalue);
            return;
        }
    }

    printf("No change");
    printf("\n");

}

void printdict(dict *dic, int size){ //for printing the output
 for(int i=0; i<size ; i++){
 printf("%s : %s\n",dic[i].key,dic[i].value);
 }
}
int main(){
    //INPUT
    int size;
    scanf("%d",&size);
    dict *dic = (dict*)malloc(size * sizeof(dict));
    for (int i = 0; i < size ; i++) {
        scanf("%s %s", dic[i].key, dic[i].value);
    }
    editdict(dic, size);
    //OUTPUT
    printdict(dic, size);
}