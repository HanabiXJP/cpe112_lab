#ifndef Fundamental_Lib_OPD_h
#define Fundamental_Lib_OPD_h

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

#define LENGTH_NAME_SURNAME 50
#define CAPACITY_HASHTABLE_OPD_DB 10

typedef struct HPI_Info{ //History of present illness
    char main_symptoms[100];
    char nature_symptoms[100];
    char symptoms_begin[50];
}HPI_Info;

typedef struct OPD_Info{ //Normal Struct
    char name_surname[LENGTH_NAME_SURNAME];
    int age;
    char gender;
    char phone_number[15];
    char address[60];
    char blood_group[6];
    float weight;
    float height;
    char congenital_disease[60];
    char drug_allergy_history[200];
    char medication_purchase_history[200];
    char medical_history[200];
    time_t appointment;
    char health_insurance_rights[100];
    HPI_Info HPI;
    char other[100];
}OPD_Info;

typedef struct OPD_LinkedList{ //LinkedList Struct
    OPD_Info OPD;
    struct OPD_LinkedList *next;
}OPD_LL;

typedef struct Queue_Disease_Examination{
    OPD_Info OPD;
    float temperature;
    int blood_pressure;
    int blood_glucose;
    float SpO2; //Oxygen in Blood OPD
    char history_taking[200];
    int queue_number;
    int priority;
}QDisease_Exam;

typedef struct SystemLogin{ //For Login
    char USER[20];
    char PASS[20];
    int RoleType;
}Login;

/*
RoleType (0-3)
0:Pharmacist
1:Physician
2:Nurse
3:Registration Officer
*/

//Static Variable (global)
extern OPD_LL *OPD_HashTable[CAPACITY_HASHTABLE_OPD_DB]; //List All OPD Database
extern unsigned long long int NumberOfOPD;

//InitOPD_LL
unsigned long getHashCode(char*); //djb2 algorithm at http://www.cse.yorku.ca/~oz/hash.html
int getIndexHash(OPD_Info); //Suggest Use to Access
OPD_Info getOPDwithName(char[]); //Get IndexHash with Name

void initOPD_HashTable(void); //Set Every Element are NULL
void freeOPD_HashTable(void); //Release Memory
void Insert_OPD_HashTable(OPD_Info*); //Insert Element of OPD
bool Delete_OPD_HashTable(OPD_Info); //Delete Element of OPD
bool Delete_OPD_HashTableWithName(char[]); //Delete Element with name
bool isOPD_in_HashTable(OPD_Info); //Check is have in OPD HashTable?
bool isName_in_HashTable(char[]); //Check is have in OPD HashTable? with Name

#endif