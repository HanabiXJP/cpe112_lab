//66070501038 Phanthach Jiamjaruschot
#include <stdio.h>
#include <string.h>

typedef struct wordPriority {

    int tier;
    char wordchar;

} wordPriority;


void enqueue(wordPriority queue[], char wordchar, int tier, int *rear);
void dequeue(wordPriority queue[], char *wordchar, int *tier, int *front);
void printResult(char word[]);

int main() {

    char word[10001];

    fgets(word, sizeof(word), stdin);

    word[strcspn(word, "\n")] = '\0';

    printResult(word);

    return 0;
}

void enqueue(wordPriority queue[], char wordchar, int tier, int *rear) {

    int i = *rear;
    while (i > 0 && queue[i - 1].tier < tier) {

    queue[i] = queue[i - 1];
    i--;
    }

    queue[i].tier = tier;
    queue[i].wordchar = wordchar;
    (*rear)++;

}

void dequeue(wordPriority queue[], char *wordchar, int *tier, int *front) {
    
    *tier = queue[*front].tier;
    *wordchar = queue[*front].wordchar;
    (*front)++;
}

void printResult(char word[]) {

    wordPriority queue[1001];

    int front = 0;
    int rear = 0;
    int stringlen = strlen(word);

    for (int i = 0; i < stringlen; i++) {

        int tier;
        char current = word[i];

        if ((current >= 'a' && current <= 'z') || (current >= 'A' && current <= 'Z')) {

            if (current == 'a' || current == 'e' || current == 'i' || current == 'o' || current == 'u'|| current == 'A' || current == 'E' || current == 'I' || current == 'O' || current == 'U') {

                tier = 3;
            }
            else {
                tier = 1;
            }
        }
        else {
            tier = 2;
        }

        enqueue(queue, current, tier, &rear);
    }

    for (int i = 0; i < stringlen; i++) {
        int tier;
        char current;
        dequeue(queue, &current, &tier, &front);
        printf("%c", current);
    }
}

