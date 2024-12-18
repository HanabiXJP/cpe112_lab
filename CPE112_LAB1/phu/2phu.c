//Jakkapat Bunjongruxsa 66070501008
#include <stdio.h>
void printSet(int arraySet[], int arraySize){
    if(arraySize == 0){
        printf("empty");
    }
    else{
        for(int i=0; i<arraySize; i++){
            printf("%d ", arraySet[i]);
        }
    }
    printf("\n");
}
int intoSet(int changeArray[], int *arraySet, int arraySize){
    int isFound;
    int setSize = 0;
    for(int i=0; i<arraySize; i++){
        isFound = 0;
        for(int j=0; j<setSize; j++){
            if(changeArray[i] == arraySet[j]){
                isFound = 1;
                break;
            }
        }
        if(isFound == 0) arraySet[setSize++] = changeArray[i];
    }
    //Return the size of the set
    return setSize;
}
int isInSet(int valueToCheck, int setCheck[], int setCheckSize){
    for(int i=0; i<setCheckSize; i++){
        if(valueToCheck == setCheck[i])
            return 1;
    }
    return 0;
}
void BubbleSort(int *sortArray, int arraySize){
    for(int i=0; i<arraySize; i++){
        for(int j=i; j<arraySize; j++){
            if(sortArray[i] > sortArray[j]){
                int temp = sortArray[i];
                sortArray[i] = sortArray[j];
                sortArray[j] = temp;
            }
        }
    }
}
void Show_SetUnion(int firstSet[], int firstSetSize, int secondSet[], int secondSetSize){
    int resultArray[firstSetSize+secondSetSize];
    int resultSet[firstSetSize+secondSetSize];
    int resultSetSize = 0;
    for(int i=0; i<secondSetSize; i++){
        resultArray[resultSetSize++] = secondSet[i];
    }
    for(int i=0; i<firstSetSize; i++){
        resultArray[resultSetSize++] = firstSet[i];
    }
    resultSetSize = intoSet(resultArray, resultSet, resultSetSize);
    BubbleSort(resultSet, resultSetSize);
    printSet(resultSet, resultSetSize);
}
void Show_Intersection(int firstSet[], int firstSetSize, int secondSet[], int secondSetSize){
    int resultSet[firstSetSize+secondSetSize];
    int resultSetSize = 0;
    for(int i=0; i<firstSetSize; i++){
        for(int j=0; j<secondSetSize; j++){
            if(firstSet[i] == secondSet[j]){
                resultSet[resultSetSize++] = firstSet[i];
                break;
            }
        }
    }
    printSet(resultSet, resultSetSize);
}
void Show_Difference(int firstSet[], int firstSetSize, int secondSet[], int secondSetSize){
    int resultSet[firstSetSize];
    int resultSetSize = 0;
    for(int i=0; i<firstSetSize; i++){
        if(isInSet(firstSet[i], secondSet, secondSetSize) == 0){
            resultSet[resultSetSize++] = firstSet[i];
        }
    }
    printSet(resultSet, resultSetSize);
}
void Show_Complement(int firstSet[], int firstSetSize, int minRange, int maxRange){
    int resultSet[maxRange-minRange+1];
    int resultSetSize = 0;
    for(int i=minRange; i<=maxRange; i++){
        if(isInSet(i, firstSet, firstSetSize) == 0){
            resultSet[resultSetSize++] = i;
        }
    }
    printSet(resultSet, resultSetSize);
}
int main(){
    //Set Universe Range
    int rangeStart, rangeEnd;
    scanf("%d %d", &rangeStart, &rangeEnd);
    //Get the first array input
    int firstArraySize;
    scanf("%d", &firstArraySize);
    int firstArray[firstArraySize], count = 0, inputValue;
    for(int i=0; i<firstArraySize; i++){
        scanf("%d", &inputValue);
        if(inputValue >= rangeStart && inputValue <= rangeEnd){
            firstArray[count++] = inputValue;
        }
    }
    firstArraySize = count;
    int setA[firstArraySize];
    int setASize = intoSet(firstArray, setA, firstArraySize);
    //Get the second array input
    int secondArraySize;
    scanf("%d", &secondArraySize);
    int secondArray[secondArraySize];
    count = 0;
    for(int i=0; i<secondArraySize; i++){
        scanf("%d", &inputValue);
        if(inputValue >= rangeStart && inputValue <= rangeEnd){
            secondArray[count++] = inputValue;
        }
    }
    secondArraySize = count;
    int setB[secondArraySize];
    int setBSize = intoSet(secondArray, setB, secondArraySize);

    printSet(setA, setASize);
    printSet(setB, setBSize);
    Show_SetUnion(setA, setASize, setB, setBSize);
    Show_Intersection(setA, setASize, setB, setBSize);
    Show_Difference(setA, setASize, setB, setBSize);
    Show_Difference(setB, setBSize, setA, setASize);
    Show_Complement(setA, setASize, rangeStart, rangeEnd);
    Show_Complement(setB, setBSize, rangeStart, rangeEnd);
    return 0;
} 