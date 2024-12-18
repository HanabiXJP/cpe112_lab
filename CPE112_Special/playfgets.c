#include <stdio.h>
#include <string.h>

int main () {

    char option[10];
    char name[10];
    scanf("%s", option);
    printf(option);

    fgets(name, sizeof(name), stdin);
    printf(name);
    
}