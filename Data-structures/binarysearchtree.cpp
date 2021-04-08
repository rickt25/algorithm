#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node{
    char nama[50];
    int umur;
    Node *left, *right;
};

Node *createNode(const char *nama, int umur){
    Node *temp = (Node*)malloc(sizeof(Node));
    strcpy(temp->nama,nama);
    temp->umur = umur;
    temp->left = temp->right = NULL;
    return temp;
}

Node *insertData(Node *curr, const char *nama, int umur){
    if(curr == NULL){
        return createNode(nama,umur);
    }
    else if(umur < curr->umur){
        curr->left = insertData(curr->left, nama, umur);
    }else{
        curr->right = insertData(curr->right,nama,umur);
    }   
}

void InOrder(Node *curr){
    if(curr == NULL) return;

    InOrder(curr->left);
    printf("%s %d\n",curr->nama, curr->umur);
    InOrder(curr->right);
}

void PostOrder(Node *curr){
    if(curr == NULL) return;

    PostOrder(curr->right);
    printf("%s %d\n",curr->nama, curr->umur);
    PostOrder(curr->left);
}

void PreOrder(Node *curr){
    if(curr == NULL) return;

    printf("%s %d\n",curr->nama, curr->umur);
    PreOrder(curr->left);
    PreOrder(curr->right);
}

int main(){
    struct Node *root = NULL;
    root = insertData(root, "daniel", 20);
    root = insertData(root, "dadrian",18);
    root = insertData(root, "dx",29);
    root = insertData(root, "du",29);
    root = insertData(root, "bebek",29);

    
    PreOrder(root);
}