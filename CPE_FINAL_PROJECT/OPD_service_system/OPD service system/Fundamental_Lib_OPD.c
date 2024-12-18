#include "Fundamental_Lib_OPD.h"

OPD_LL *OPD_HashTable[CAPACITY_HASHTABLE_OPD_DB];
unsigned long long int NumberOfOPD;

void removeSpaceRepeat(char *str){
    char *token,src[LENGTH_NAME_SURNAME];
    strcpy(src,str);
    token = strtok(src, " ");
    strcpy(str,"");
    while (token != NULL) {
        strcat(str,token);
        strcat(str," ");
        token = strtok(NULL, " ");
    }
    str[strlen(str)-1] = '\0';
}

unsigned long getHashCode(char *str){
    unsigned long hash_code = 5381;
    int c;
    while ((c = *str++))
        hash_code = ((hash_code<<5)+hash_code)+c; /* hase * 33 + c*/
    return hash_code;
}

int getIndexHash(OPD_Info opd){
    return getHashCode(opd.name_surname)%CAPACITY_HASHTABLE_OPD_DB;
}

OPD_Info getOPDwithName(char _name[]){
    OPD_LL *ptr = OPD_HashTable[getHashCode(_name)%CAPACITY_HASHTABLE_OPD_DB];
    while (ptr!=NULL && strcmp(ptr->OPD.name_surname,_name)!=0)
        ptr = ptr->next;
    return ptr->OPD; 
}

void initOPD_HashTable(void){
    for (int i=0;i<CAPACITY_HASHTABLE_OPD_DB;i++)
        OPD_HashTable[i] = NULL;
    NumberOfOPD = 0;
}

void freeOPD_HashTable(void){
    for (int i=0;i<CAPACITY_HASHTABLE_OPD_DB;i++){
        OPD_LL *ptr = OPD_HashTable[i];
        while (ptr!=NULL){
            OPD_LL *next_ptr = ptr->next;
            free(ptr);
            ptr = next_ptr;
        }
    }
}

void Insert_OPD_HashTable(OPD_Info *opd_new){

    removeSpaceRepeat(opd_new->name_surname);
    strlwr(opd_new->name_surname);
    if (isName_in_HashTable(opd_new->name_surname))
        return;

    int index = getIndexHash(*opd_new);
    OPD_LL *ptr = OPD_HashTable[index];
    //bool isFound = false;
    if (ptr!=NULL){
        /*while (ptr->next!=NULL){
            if (strcmp(ptr->OPD.name_surname,opd_new->name_surname)==0){
                isFound = true;
                break;
            }
            ptr = ptr->next;
        }
        if (!isFound){*/
        ptr->next = (OPD_LL*) calloc(1,sizeof(OPD_LL));
        ptr->next->OPD = *opd_new;
        ptr->next->next = NULL;
        //}
    }else {
        OPD_HashTable[index] = (OPD_LL*) calloc(1,sizeof(OPD_LL));
        OPD_HashTable[index]->OPD = *opd_new;
        OPD_HashTable[index]->next = NULL;
    }
    NumberOfOPD++;
}

bool Delete_OPD_HashTable(OPD_Info opd_des){
    int index = getIndexHash(opd_des);
    OPD_LL *ptr = OPD_HashTable[index];
    OPD_LL *pre_ptr = NULL;
    if (ptr==NULL)
        return false;
    while (ptr!=NULL && strcmp(ptr->OPD.name_surname,opd_des.name_surname)!=0){
        pre_ptr = ptr;
        ptr = ptr->next;
    }
    if (ptr==NULL)
        return false;
    if (pre_ptr==NULL){
        OPD_HashTable[index] = ptr->next;
        free(ptr);
    }else if (ptr->next!=NULL){
        pre_ptr->next = ptr->next;
        free(ptr);
    }else if(ptr!=NULL && strcmp(ptr->OPD.name_surname,opd_des.name_surname)==0){
        pre_ptr->next = NULL;
        free(ptr);
    }
    NumberOfOPD--;
    return true;
}

bool isOPD_in_HashTable(OPD_Info opd){
    int index = getIndexHash(opd);
    OPD_LL *ptr = OPD_HashTable[index];
    while (ptr!=NULL){
        if (strcmp(ptr->OPD.name_surname,opd.name_surname)==0)
            return true;
        ptr = ptr->next;
    }
    return false;
}

bool isName_in_HashTable(char _name[]){
    OPD_LL *ptr = OPD_HashTable[getHashCode(_name)%CAPACITY_HASHTABLE_OPD_DB];
    while (ptr!=NULL && strcmp(ptr->OPD.name_surname,_name)!=0)
        ptr = ptr->next;
    if (ptr==NULL)
        return false;
    return isOPD_in_HashTable(ptr->OPD);
}

bool Delete_OPD_HashTableWithName(char _name[]){
    return Delete_OPD_HashTable(getOPDwithName(_name));
}