#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 10
struct Node{
    char name[25];
    Node *next;
};

Node *head[SIZE], *tail[SIZE];

Node* createNode(const char* name){
    Node* temp = (Node*)malloc(sizeof(Node));
    strcpy(temp->name,name);
    temp->next = NULL;
    return temp;
}

int Hash(const char* name){
    int count = 0;
    for(int i=0; i<strlen(name); i++)
        count += name[i];
    return count%SIZE;
}

Node* Search(const char* name){
    int idx = Hash(name);
    Node* curr = head[idx];
    while(curr){
        if(strcmp(curr->name,name) == 0)
            return curr;
        curr = curr->next; 
    }
    return NULL;
}

void Insert(const char* name){
    Node* temp = createNode(name);
    int idx = Hash(name);

    if(!head[idx])
        head[idx] = tail[idx] = temp;
    else{
        tail[idx]->next = temp;
        tail[idx] = temp;
    }
}

void Update(const char* name, const char* edit){
    Node* temp = Search(name);
    if(temp) strcpy(temp->name, edit);
    else printf("%s not found\n", name);
}

void Delete(const char* name){
    int idx = Hash(name);
    Node *curr = head[idx], *prev;
    while(curr){
        if(strcmp(curr->name,name) == 0){
            if(curr == head[idx]){
                if(!curr->next){
                    head[idx] = tail[idx] = head[idx]->next = NULL;
                    free(curr);
                }else{
                    Node* temp = curr->next;
                    head[idx]->next = NULL;
                    free(head[idx]);
                    head[idx] = temp;
                }
            }else if(curr == tail[idx]){
                prev->next = NULL;
                free(tail[idx]);
                tail[idx] = prev;
            }else{
                Node* temp = curr->next;
                curr->next = NULL;
                free(curr);
                prev->next = temp;
            }
        }
        prev = curr;
        curr = curr->next;
    }
}

void Print(){
    for(int i=0; i<=SIZE; i++){
        printf("%d. ",i);
        Node* curr = head[i];
        while(curr){
            if(curr == head[i]) printf("(head)");
            if(curr == tail[i]) printf("(tail)");
            printf("%s -> ", curr->name);
            curr = curr->next;
        }
        puts("");
    }
}


int main(){
    Insert("Budi");
    Insert("Anton");
    Insert("Kucing");
    Update("Budi","Badu");
    Delete("Kucing");
    Print();
}
