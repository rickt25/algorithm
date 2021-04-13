#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASHSIZE 20
struct Node{
    char name[25];
    struct Node* next;
};

Node* hashTable[HASHSIZE];

Node* createNode(const char* name){
    Node* temp = (Node*)malloc(sizeof(Node));
    strcpy(temp->name,name);
    temp->next = NULL;
    return temp;
}

int Hash(const char* name){
    int count;
    for(int i=0; i<strlen(name); i++)
        count += name[i];
    return count%HASHSIZE;
}

void Insert(const char* name){
    Node* temp = createNode(name);
    int hashIdx = Hash(name);

    if(hashTable[hashIdx] != NULL)
        temp->next = hashTable[hashIdx];
    
    hashTable[hashIdx] = temp;
    return;
}

void Print(){
    for(int i=0; i<=HASHSIZE; i++){
        Node* curr = hashTable[i];
        while(curr){
            printf("%s\n", curr->name);
            curr = curr->next;
        }
    }
}


int main(){
    Insert("Budi");
    Insert("Angga");
    Insert("Caonima");
    Print();
}
