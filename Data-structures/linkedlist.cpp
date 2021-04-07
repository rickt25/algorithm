#include<stdio.h>
#include<stdlib.h>

struct Node{
    int value;
    struct Node *next;
} *head, *tail;

Node* createNode(int input){
    Node *temp = (Node*)malloc(sizeof(Node));
    temp->value = input;
    temp->next = NULL;
    return temp;
}

void PushHead(int input){
    Node *temp = createNode(input);
    
    if(head) temp->next = head;
    else tail = temp;
    head = temp;
    return;
}

void PushTail(int input){
    Node *temp = createNode(input);
    
    if(tail) tail->next = temp;
    else head = temp;
    tail = temp;
    return;
}

void PushMid(int input, int index){
    Node *temp = createNode(input);
    Node *curr = head;

    while(curr && index > 0){
        curr = curr->next;
        index--;
    }

    if(curr != NULL){
        temp->next = curr->next;
        curr->next = temp;
    }

    return;
}

void PopHead(){
    if(!head) return;
    else if(head == tail){
        free(head);
        head = tail = NULL;
    }
    else{
        Node *temp = head->next;
        head->next = NULL;
        free(head);
        head = temp;
    }
}

void PopTail(){
    if(!head) return;
    else if(head == tail){
        free(head);
        head = tail = NULL;
    }
    else{
        Node *curr = head;
        while(curr->next != tail){
            curr = curr->next;
        }
        curr->next = NULL;
        free(tail);
        tail = curr;
    }
}

int main(){

}