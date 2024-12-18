#include "Utility_UI.h"

void getWindowsSize_For_Testing(void){
    while (1){
        CONSOLE_SCREEN_BUFFER_INFO csbi;
        int columns, rows;

        GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
        columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
        rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

        printf("columns: %d\n", columns);
        printf("rows: %d\n", rows);
        getch();
    }
}

void deleteLineTerminal(int line){
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int columns, rows;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    //rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
    printf("\e[1A");
    for (int i=0;i<line;i++)
        printf("%.*s",columns-1,__TERMINAL_BLANK);
    printf("\n\e[1A");
}