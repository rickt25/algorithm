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
    char infix[255], posfix[255];

    printf("Input notasi infix : ");
    scanf("%[^\n]",infix);
    int idx = 0;

    for(int i=0; i<=strlen(infix); i++){
        if(isalnum(infix[i])) posfix[idx++] = infix[i];
        else{
            if(infix[i] == ' ') continue;
            else if(infix[i] == '(') Push(infix[i]);
            else if(infix[i] == ')'){
                while(top && top->value != '('){
                    posfix[idx++] = top->value;
                    Pop();
                }
                Pop();
            }
            else{
                while(top && Precedence(top->value) >= Precedence(infix[i])){
                    posfix[idx++] = top->value;
                    Pop();
                }
                Push(infix[i]);
            }
        }
    }

    while(top){
        posfix[idx++] = top->value;
        Pop();
    }
    
    printf("Hasil konversi ke posfix : %s\n",posfix);
}
