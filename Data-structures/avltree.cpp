#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node{
	int key;
	char name[20];
	int height, balance;
	Node *left, *right;
};

Node* CreateNode(int key, const char* name){
	Node* newNode = (Node*) malloc (sizeof(Node));
	newNode->key = key;
	strcpy(newNode->name, name);
	return newNode;
}

int max(int a, int b){
	return a > b ? a : b;
}

int getHeight(Node* curr){
	if(!curr) return 0;
	return curr->height;
}

int getBalance(Node* curr){
	if(!curr) return 0;
	return getHeight(curr->left) - getHeight(curr->right);
}

Node* leftRotate(Node* curr){
	Node *middle = curr->right;
	Node *lostChild = middle->left;

	middle->left = curr;
	curr->right = lostChild;

	curr->height = max(getHeight(curr->left), getHeight(curr->right)) + 1;
	middle->height = max(getHeight(middle->left), getHeight(middle->right)) + 1;

	return middle;
}

Node* rightRotate(Node* curr){
	Node *middle = curr->left;
	Node *lostChild = middle->right;

	middle->right = curr;
	curr->left = lostChild;

	curr->height = max(getHeight(curr->left), getHeight(curr->right)) + 1;
	middle->height = max(getHeight(middle->left), getHeight(middle->right)) + 1;

	return middle;
}

Node* Balancing(Node* curr){
	int balance = getBalance(curr);

	if(balance > 1 && getBalance(curr->left) >= 0){
			return rightRotate(curr);
	}else if(balance > 1 && getBalance(curr->left) < 0){
			curr->left = leftRotate(curr->left);
			return rightRotate(curr);
	}else if(balance < -1 && getBalance(curr->right) <= 0){
			return leftRotate(curr);
	}else if(balance < -1 && getBalance(curr->right) > 0){
			curr->right = rightRotate(curr->right);
			return leftRotate(curr);
	}

	return curr;
}

Node* InsertNode(Node* curr, int key, const char* name){
	if(!curr){
			return CreateNode(key, name);
	}
	else if(key < curr->key){
			curr->left = InsertNode(curr->left, key, name);
	}
	else if(key > curr->key){
			curr->right = InsertNode(curr->right, key, name);
	}

	return Balancing(curr);
}

Node* SearchNode(Node *curr , int key){
	if(!curr){
			return NULL;
	}
	else if(curr->key > key){
			return SearchNode(curr->left, key);
	}
	else if(curr->key < key){
			return SearchNode(curr->right, key);
	}
	else{
			return curr;
	}
}

Node *FindPredecessor(Node *curr){
	Node *temp = curr->left;
	while (temp->right){
		temp = temp->right;
	}
	return temp;
}

Node* DeleteNode(Node *curr, int key){
	if(!curr){
			return NULL;
	}
	else if(curr->key > key){
			curr->left = DeleteNode(curr->left, key);
	}
	else if(curr->key < key){
			curr->right = DeleteNode(curr->right, key);
	}
	else{
			if(curr->left == NULL && curr->right == NULL){
					free(curr);
					curr = NULL;
					return NULL;
			}
			else if(curr->left){
					Node* temp = curr->left;
					free(curr);
					curr = NULL;
					return temp;
			}
			else if(curr->right){
					Node* temp = curr->right;
					free(curr);
					curr = NULL;
					return temp;
			}
			else{
					Node *temp = FindPredecessor(curr);
					curr->key = temp->key;
					strcpy(curr->name, temp->name);
					curr->left = DeleteNode(curr->left, key);
			}
	}
	return Balancing(curr);
}

void InOrder(Node *curr){
	if(!curr) return;

	InOrder(curr->left);
	printf("%d\n", curr->key);
	InOrder(curr->right);
}

void PreOrder(Node *curr){
	if(!curr) return;

	printf("%d\n", curr->key);
	PreOrder(curr->left);
	PreOrder(curr->right);
}

void PostOrder(Node *curr){
	if(!curr) return;

	PostOrder(curr->left);
	PostOrder(curr->right);
	printf("%d\n", curr->key);
}

int main(){
	Node* root = NULL;

	root = InsertNode(root, 1000, "proxima");
	root = InsertNode(root, 1500, "mars");
	root = InsertNode(root, 2500, "venus");
	root = InsertNode(root, 3500, "earth");
	root = InsertNode(root, 3900, "jupiter");
	root = InsertNode(root, 6400, "uranus");
	root = InsertNode(root, 79850, "saturn");
	root = InsertNode(root, 150350, "neptune");

	InOrder(root);
}