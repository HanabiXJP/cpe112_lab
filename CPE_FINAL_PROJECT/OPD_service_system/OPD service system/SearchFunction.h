#ifndef SearchFunction_h
#define SearchFunction_h

#include "Fundamental_Lib_OPD.h"
#include "Utility_UI.h"

#define CHILDERN_LETTER_TRIE 28

typedef struct Trie_Name {
  struct Trie_Name* children[CHILDERN_LETTER_TRIE];
  bool isEndOfWord;
  char* word;
} Trie_Name;

extern Trie_Name* root_name_search;

void createMember(char[],int,char,char[],char[],char[]); //For Testing
void init_Trie_Name(void);
Trie_Name* newTrie_Name(void);
//void insert(char* word);
//void _insert(Trie_Name* root, char* word);
//int search_engine_list(char* prefix, char* results[], int results_count);
int search_engine_list_range(char*, char*[], int,int);
void SearchUI(void); //Main For Use

#endif