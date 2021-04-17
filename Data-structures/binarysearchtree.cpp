#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node{
    char nama[50];
    int umur;
    Node *left, *right;
};

Node* createNode(const char *nama, int umur){
    Node *temp = (Node*)malloc(sizeof(Node));
    strcpy(temp->nama,nama);
    temp->umur = umur;
    temp->left = temp->right = NULL;
    return temp;
}

Node* Insert(Node *curr, const char *nama, int umur){
    if(curr == NULL)
        return createNode(nama,umur);
    else if(umur < curr->umur)
        curr->left = Insert(curr->left, nama, umur);
    else
        curr->right = Insert(curr->right,nama,umur);
}

Node *inOrderSuccessor(Node *root) {
    Node *curr = root->right;
    while(curr && curr->left) 
        curr = curr->left;
    return curr;
}

Node *inOrderPredecessor(Node *root) {
    Node *curr = root->left;
    while(curr && curr->right)
        curr = curr->right;
    return curr;
}

Node* Delete(Node *curr, int umur){
    if(!curr)
        return curr;
    else if(umur < curr->umur)
        curr->left = Delete(curr->left, umur);
    else if(umur > curr->umur)
        curr->right = Delete(curr->right, umur);
    else{
        if(!curr->left || !curr->right){
            Node *temp = curr->left ? curr->left : curr->right;
            curr->left = curr->right = NULL;
            free(curr);
            curr = NULL;
            return temp;
        }

        Node* temp = inOrderSuccessor(curr);
        strcpy(curr->nama,temp->nama);
        curr->umur = temp->umur;
        
        curr->right = Delete(curr, umur);
    }

    return curr;
}

void InOrder(Node *curr){
    if(!curr) return;

    InOrder(curr->left);
    printf("%s %d\n",curr->nama, curr->umur);
    InOrder(curr->right);
}

void PostOrder(Node *curr){
    if(!curr) return;

    PostOrder(curr->right);
    printf("%s %d\n",curr->nama, curr->umur);
    PostOrder(curr->left);
}

void PreOrder(Node *curr){
    if(!curr) return;

    printf("%s %d\n",curr->nama, curr->umur);
    PreOrder(curr->left);
    PreOrder(curr->right);
}

int main(){
    struct Node *root = NULL;
    root = Insert(root, "daniel", 20);
    root = Insert(root, "dadrian",18);
    root = Insert(root, "dx",29);
    root = Insert(root, "du",29);
    root = Insert(root, "bebek",29);

    
    PreOrder(root);
}