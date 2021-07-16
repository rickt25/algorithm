#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

struct Stack{
    char value;
    Stack *next;
} *top;

struct Stack *CreateStack(char value){
    Stack *temp = (Stack*)malloc(sizeof(Stack));
    temp->value = value;
    temp->next = NULL;
    return temp;
}

void Push(char value){
    Stack* temp = CreateStack(value);
    if(!top){
        top = temp;
    }else{ 
        temp->next = top; 
        top = temp;
    }
}

void Pop(){
    if(top){
        Stack* temp = top->next;
        top->next = NULL;
        free(top);
        top = temp;
    }else{ 
        top = NULL;
    }
}

int Precedence(char symbol){
    if(symbol == '^') return 3;
    else if(symbol == '*' || symbol == '/') return 2;
    else if(symbol == '+' || symbol == '-') return 1;
    else return 0;
}

int main(){
    char infix[255], prefix[255];

    printf("Input notasi infix : ");
    scanf("%[^\n]",infix);
    int idx = 0;

    for(int i=strlen(infix); i>=0; i--){
        
    }
    
    printf("Hasil konversi ke prefix : %s\n",prefix);
}
