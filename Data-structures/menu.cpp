#include <stdio.h>
#include<stdlib.h>

void open(int menu){
    switch(menu){
        case 1: puts("Faq"); break;
        case 2: puts("Nothin much"); break;
        case 3: return;
        default: puts("Invalid menu"); break;
    }
    getchar();
}

void menu(){

    int menu = -1;
    do{
        system("@cls|clear");
        puts("|-----------------------|");
        puts("|        MAIN MENU      |");
        puts("|-----------------------|");
        puts("|  1. Do something      |");
        puts("|  2. What do you want  |");
        puts("|  3. Exit              |");
        puts("|-----------------------|");

        printf(">> ");
        scanf("%d",&menu); getchar();
        open(menu);
    }while(menu != 3);

    printf("Bye");
}

int main(){
    menu();
}