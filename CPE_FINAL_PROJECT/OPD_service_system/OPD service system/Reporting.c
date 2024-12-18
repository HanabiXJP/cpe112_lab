#include "Reporting.h"

void Reporting(OPD_Info opd){ //Then I will organize it to be more beautiful than before.
    printf("==================================Reporting==================================\n");
    printf("= > name : %s\n",opd.name_surname);
    printf("= > age  : %d\n",opd.age);
    printf("= > phone number : %s\n",opd.phone_number);
    printf("= > address      : %s\n",opd.address);
    printf("= > blood group  : %s\n",opd.blood_group);
    printf("=============================================================================\n");
    printf(" Press any to exit\n");
    getch();
    system("cls");
}