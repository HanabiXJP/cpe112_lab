#include "Fundamental_Lib_OPD.h"
#include "SearchFunction.h"
#include "Reporting.h"


void CreateTestingCase(){
    createMember("abcdefghijklmnopqrstuvwxyzabc i",34,'F',"012-345-6789","address2","B");
    createMember("izawakilza",30,'F',"012-345-6789","address1","A");
    createMember("ayuo",60,'F',"012-345-6789","address2","AB+");
    createMember("maako",300,'F',"012-345-6789","addre0ss1","A");
    createMember("met e",34,'F',"012-345-6789","address2","B");
    createMember("maho ma",60,'F',"012-345-6789","address2","AB+");
    createMember("line",30,'F',"012-345-6789","address1","A");
    createMember("linef",30,'F',"012-345-6789","address1","A");
    createMember("mayu malla",34,'F',"012-345-6789","address2","B");
    createMember("navera",60,'F',"012-345-6789","address2","AB+");
    createMember("mper",30,'F',"012-345-6789","address1","A");
    createMember("magg",34,'F',"012-345-6789","address2","B");
    createMember("maggg",60,'F',"012-345-6789","address2","AB+");
    createMember("magiez",60,'F',"012-345-6789","address2","AB+");
    createMember("ma",60,'F',"012-345-6789","address2","AB+");
    createMember("maa",60,'F',"012-345-6789","address2","AB+");
    createMember("ma .shH",60,'F',"012-345-6789","address2","AB+");
    createMember("ma .shh",60,'F',"012-345-6789","address2","AB+");
    createMember("ma      sa",60,'F',"012-345-6789","address2","AB+");
    createMember("ma sax",60,'F',"012-345-6789","address2","AB+");
    createMember("arya",60,'F',"012-345-6789","address2","AB+");
    createMember("zono",60,'F',"012-345-6789","address2","AB+");
    createMember("fa kenzo",60,'F',"012-345-6789","address2","AB+");
    createMember("uizo sa",60,'F',"012-345-6789","address2","AB+");
    createMember("Kumz ad czx",60,'F',"012-345-6789","address2","AB+");
    createMember("Navida ad",60,'F',"012-345-6789","address2","AB+");
    createMember("Heart Dontknow",60,'F',"012-345-6789","address2","AB+");
}

void testSearch(void){
    while (true){
        int start,end;
        printf("start=");
        scanf(" %d",&start);
        printf("end=");
        scanf(" %d",&end);
        char *result[end-start+1];
        int len_list = search_engine_list_range("",result,start,end);
        printf(">Result Search are (%d)\n",len_list);
        for (int i=0;i<len_list;i++){
            printf("%s\n",result[i]);
        }
        getch();
        system("cls");   
    }
}

int main(void) { //Auto uncapilizd
    initOPD_HashTable(); //For Init in Main only not for other funtion
    CreateTestingCase();
    init_Trie_Name();
    
    //printf("\e[8;20;200");
    //printf("Number All OPD %llu\n",NumberOfOPD);
    //Reporting(getOPDwithName("maako"));
    //testSearch();
    deleteLineTerminal(1);
    SearchUI();
    printf("Eh you want exit ???\n");
    getch();
    freeOPD_HashTable(); //For exit program
    return 0;
}
