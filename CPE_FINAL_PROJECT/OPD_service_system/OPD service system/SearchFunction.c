#include "SearchFunction.h"
#include "Fundamental_Lib_OPD.h"
#include "Reporting.h"
#include <ctype.h>

Trie_Name* root_name_search;

void _insert(Trie_Name* root, char* word);

void createMember(char name[],int age,char gender,char phone_number[],char address[],char blood_group[]){
    OPD_Info opd;
    strcpy(opd.name_surname,name);
    opd.age = age;
    opd.gender = gender;
    strcpy(opd.phone_number,phone_number);
    strcpy(opd.address,address);
    strcpy(opd.blood_group,blood_group);
    Insert_OPD_HashTable(&opd);
}

void init_Trie_Name(void){
    root_name_search = newTrie_Name();//OPD_HashTable[i] = NULL;
    for (int i=0;i<CAPACITY_HASHTABLE_OPD_DB;i++){
        if (OPD_HashTable[i] != NULL){
            OPD_LL *ptr = OPD_HashTable[i];
            while (ptr!=NULL){
                //printf("add %s\n",ptr->OPD.name_surname);
                _insert(root_name_search, ptr->OPD.name_surname);
                ptr = ptr->next;
            }
        }
    }
}

Trie_Name* newTrie_Name(void) {
    Trie_Name* node = (Trie_Name*)malloc(sizeof(Trie_Name));
    for (int i = 0; i < CHILDERN_LETTER_TRIE; i++) {
        node->children[i] = NULL;
    }
    node->isEndOfWord = false;
    node->word = NULL;
    return node;
}
/* Maximize Letter Not Improve dot
int letterToindexTrie(char C){
    if (C==' ')
        return 0;
    else if (C<'a')
        return (C - 'A')+27;
    else
        return C - 'a' + 1;
}

char indexToletterTrie(int index){
    if (index==0)
        return ' ';
    else if (index>26)
        return (index-27) + 'A';
    else
        return index + 'a' - 1;
}
*/

int letterToindexTrie(char C){
    if (C==' ')
        return 0;
    else if (C=='.')
        return 1;
    else
        return C - 'a' + 2;
}

char indexToletterTrie(int index){
    if (index==0)
        return ' ';
    else if (index==1)
        return '.';
    else
        return index + 'a' - 2;
}

void _insert(Trie_Name* root, char* word){
    Trie_Name* current = root;
    for (int i = 0; word[i] != '\0'; i++) {
        int index = letterToindexTrie(word[i]);
        if (current->children[index] == NULL) {
            current->children[index] = newTrie_Name();
        }
        current = current->children[index];
    }
    current->isEndOfWord = true;
    current->word = word;
}

void insert(char* word){
    _insert(root_name_search,word);
}

/*void _search_trie_list(Trie_Name* root, char* prefix,int sizeprefix, char* buffer, int buffer_size, char* results[], int* results_count,int need_results){
    if (root == NULL || *results_count >= need_results)
        return;
    if (root->isEndOfWord && strncmp(prefix, root->word, sizeprefix) == 0) {
        results[*results_count] = malloc(strlen(root->word) + 1);
        strcpy(results[*results_count], root->word);
        (*results_count)++;
        for (int i = 0; i < CHILDERN_LETTER_TRIE; i++) {
            if (root->children[i] != NULL) {
                char* new_buffer = malloc(buffer_size + 2);
                strcpy(new_buffer, buffer);
                new_buffer[buffer_size] = indexToletterTrie(i);
                new_buffer[buffer_size + 1] = '\0';
                _search_trie_list(root->children[i], prefix,sizeprefix, new_buffer, buffer_size + 1, results, results_count,need_results);
                free(new_buffer);
            }
        }
    } else {
        for (int i = 0; i < CHILDERN_LETTER_TRIE; i++) {
            if (root->children[i] != NULL) {
                buffer[buffer_size] = indexToletterTrie(i);
                _search_trie_list(root->children[i], prefix,sizeprefix, buffer, buffer_size, results, results_count,need_results);
            }
        }
    }
}

int search_engine_list(char* prefix, char* results[], int results_count){
    char buffer[100];
    int results_count_temp = 0;
    int buffer_size = 0;
    _search_trie_list(root_name_search,prefix,strlen(prefix),buffer,buffer_size,results,&results_count_temp,results_count);
    return results_count_temp;
}*/

void _search_trie_list_range(Trie_Name* root, char* prefix,int sizeprefix, char* buffer, int buffer_size, char* results[], int* results_count,int *start,int end,int *count){
    if (root == NULL || *count > end-1)
        return;
    if (root->isEndOfWord && strncmp(prefix, root->word, sizeprefix) == 0) {
        if (*count >= *start){
            results[*results_count] = malloc(strlen(root->word) + 1);
            strcpy(results[*results_count], root->word);
            (*results_count)++;
        }
        (*count)++;
        for (int i = 0; i < CHILDERN_LETTER_TRIE; i++) {
            if (root->children[i] != NULL) {
                char* new_buffer = malloc(buffer_size + 2);
                strcpy(new_buffer, buffer);
                new_buffer[buffer_size] = indexToletterTrie(i);
                new_buffer[buffer_size + 1] = '\0';
                _search_trie_list_range(root->children[i], prefix,sizeprefix, new_buffer, buffer_size + 1, results, results_count,start,end,count);
                free(new_buffer);
            }
        }
    } else {
        for (int i = 0; i < CHILDERN_LETTER_TRIE; i++) {
            if (root->children[i] != NULL) {
                buffer[buffer_size] = indexToletterTrie(i);
                _search_trie_list_range(root->children[i], prefix,sizeprefix, buffer, buffer_size, results, results_count,start,end,count);
            }
        }
    }
}

int search_engine_list_range(char* prefix, char* results[], int start,int end){
    char buffer[100];
    int results_count_temp = 0;
    int buffer_size = 0;
    int _start=start;
    int count = 0;
    _search_trie_list_range(root_name_search,prefix,strlen(prefix),buffer,buffer_size,results,&results_count_temp,&_start,end,&count);
    return results_count_temp;
}

char *getSubRemainText(char *str, int start) {
    if (start < 0 || start > strlen(str))
        return NULL;  // Invalid range
    
    int subStrLen = strlen(str) - start + 1;  // Length of substring
    char *subStr = malloc(subStrLen + 1);  // Allocate memory for substring
    if (!subStr)
        return NULL;  // Memory allocation failed
    for (int i = start, j = 0; i < strlen(str) + 1; i++, j++)
        subStr[j] = str[i];
    subStr[subStrLen] = '\0';
    return subStr; 
}

void list_search(char *name,int select,char *list[]){
    int len = search_engine_list_range(name,list,0,10),i=0;
    for (;i<len;i++){
        if (i==select)
            printf("\x1b[38;5;47m");
        printf("%d. %c",i+1,toupper(list[i][0]));
        for (int j=1;j<strlen(list[i]);j++)
            if (list[i][j-1]==' ' && (list[i][j]>='a' && list[i][j]<='z') && i+1 < strlen(list[i]))
                printf("%c",toupper(list[i][j]));
            else
                printf("%c",list[i][j]);
        //printf("%d. %s",i+1,list[i]);
        printf("%.*s\n",LENGTH_NAME_SURNAME-(len+2),__TERMINAL_BLANK);
        if (i==select)
            printf("\e[0m");
    }
    for (;i<10;i++){
        strcpy(list[i],"");
        if (i==select)
            printf("\x1b[38;5;47m");
        printf("%d. -",i+1);
        printf("%.*s\n",LENGTH_NAME_SURNAME-2,__TERMINAL_BLANK);
        if (i==select)
            printf("\e[0m");
    }
}

void SearchUI(void) {
    int cursor=0;
    int cursor_scorll=0;
    int max_scroll=9;
    char text[LENGTH_NAME_SURNAME]="";
    char output_text[LENGTH_NAME_SURNAME]="";
    char key = ' ';
    char *list[10];
    int result_start_pos = 2;

    bool isChange=true;
    bool isUpdateSelect=false;
    bool _text_not_change = true;
    bool is_reset = true;

    while (true){

        if (is_reset){
            printf("Name-Surname : ");
            is_reset = false;
            _text_not_change = true;
            isChange=true;
            printf("\e[%d;%dH%s",1,16,output_text);
        }

        if (isChange){
            printf("\e[%d;%dH",result_start_pos,1);
            list_search(text,cursor_scorll,list);
            isChange = false;
        }

        if (_text_not_change){
            printf("You can type anything not change!\n");
            _text_not_change=false;
        }

        int len = strlen(text);
        printf("\e[%d;%dH",1,16+cursor);
        key = getch();
        if (key==8 && cursor>0){ //del
            if (cursor == len){
                printf("\e[1D \e[1D");
                text[cursor-1]='\0';
                output_text[cursor-1]='\0';
                cursor--;
            }else{
                char *remain = getSubRemainText(output_text,cursor);
                printf("\e[1D%s ",remain);
                text[cursor-1]='\0';
                output_text[cursor-1]='\0';
                printf("\e[%dD",strlen(remain)+1);
                strcat(text,remain);
                strcat(output_text,remain);
                cursor--;
            }
            isChange=true;
        }else if (key==75 && cursor>0){ //left
            printf("\e[1D");
            cursor--;
        }else if (key==77 && cursor<len){ //right
            printf("\e[1C");
            cursor++;
        }else if (((key>='a' && key<='z') || key==' ') && len<LENGTH_NAME_SURNAME){
            if (cursor == len){
                if (cursor==0 || output_text[cursor!=0?cursor-1:0]==' '){
                    printf("%c",toupper(key));
                    output_text[cursor] = toupper(key);
                }else{
                    printf("%c",key);
                    output_text[cursor] = key;
                }
                text[cursor]=key;
                cursor++;
            }else{
                char *remain = getSubRemainText(output_text,cursor);
                if (output_text[cursor!=0?cursor-1:0]==' ' || cursor==0){
                    printf("%c",toupper(key));
                    output_text[cursor] = toupper(key);
                }else{
                    printf("%c",key);
                    output_text[cursor] = key;
                }
                printf("%s",remain);
                text[cursor]=key;
                text[cursor+1]='\0';
                output_text[cursor+1]='\0';
                printf("\e[%dD",strlen(remain));
                strcat(text,remain);
                strcat(output_text,remain);
                cursor++;
            }
            isChange=true;
        }else if (key==80 && cursor_scorll<max_scroll){ //up
            cursor_scorll++;
            isChange=true;
        }else if (key==72 && cursor_scorll>0){ //down
            cursor_scorll--;
            isChange=true;
        }else if (key==13){
            if (isName_in_HashTable(list[cursor_scorll])){
                system("cls");
                Reporting(getOPDwithName(list[cursor_scorll]));
                is_reset = true;
            }
        }
    }
}