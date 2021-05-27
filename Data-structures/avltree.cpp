#include<stdio.h>
#include<stdlib.h>

struct Node{
    int value;
    int height;
    Node *left, *right;
};

int max(int a, int b){
    if(a > b) return a;
    return b;
}

int getHeight(Node* curr){
    if(!curr) return 0;
    return curr->height;
}

int getBalance(Node* curr){
    if(!curr) return 0;
    return getHeight(curr->left) - getHeight(curr->right);
}

Node* leftRotate(Node* x){
    Node *r = x->right;
    Node *l = r->left;

    r->left = x;
    x->right = l;

    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    r->height = max(getHeight(r->left), getHeight(r->right)) + 1;

    return r;
}

Node* rightRotate(Node* x){
    Node *l = x->left;
    Node *r = l->right;

    l->right = x;
    x->left = r;

    l->height = max(getHeight(l->left), getHeight(l->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return l;
}

Node* insert(Node* curr, int value){
    if(!curr){
        curr = (Node*) malloc(sizeof(Node));
        curr->value = value;
        curr->height = 1;
        curr->left = curr->right = NULL;
    }
    else if(value < curr->value) curr->left = insert(curr->left, value);
    else curr->right = insert(curr->right, value);

    int height = max(getHeight(curr->left),getHeight(curr->right)) + 1;
    int balance = getBalance(curr);
    curr->height = height;

    // left left rotation
    if(balance > 1 && value < curr->left->value){
        return rightRotate(curr);
    }
    //lef right rotation
    if(balance > 1 && value > curr->left->value){
        curr->left = leftRotate(curr->left);
        return rightRotate(curr);
    }
    // right right rotation
    if(balance < -1 && value > curr->right->value){
        return leftRotate(curr);
    }
    // right left rotation
    if(balance < -1 && value < curr->right->value){
        curr->right = rightRotate(curr->right);
        return leftRotate(curr);
    }
}

void PreOrder(Node *curr){
    if(!curr) return;

    printf("%d\n",curr->value);
    PreOrder(curr->left);
    PreOrder(curr->right);
}

Node *findPredecessor(Node *curr){
	Node *temp = curr->left;
	while (temp->right){
		temp = temp->right;
	}
	return temp;
}

Node *deleteNode(Node *curr, int value){
	//kalau misalkan ga ketemu
	if (!curr)
		return NULL;
	//kalau misal valuenya lebih kecil dari curr (ke kiri)
	else if(value < curr->value){
		curr->left = deleteNode(curr->left, value);
	}
	//kalau misal valuenya lebih besar dari curr (ke kanan)
	else if(value > curr->value){
		curr->right = deleteNode(curr->right, value);
	}
	// kalau udah ketemu
	else{
		// kalau ga ada child sama sekali
		if(curr->left==NULL &&curr->right==NULL){
			//delete
			free(curr);
			curr = NULL;
			return curr;
		}
		//kalau punya 1 child
		if(curr->left==NULL){
			//kalau ada anak kanan
			Node *temp = curr->right;
			free(curr);
			curr = NULL;
			return temp;
		}
		else if(curr->right==NULL){
			//kalau ada anak kiri
			Node *temp = curr->left;
			free(curr);
			curr = NULL;
			return temp;
		}
		//kalau ada 2 child
		//pakai predecessor
		Node *temp = findPredecessor(curr);
		curr->value = temp->value;
		
		//hapus sis predecessorr
		curr->left = deleteNode(curr->left, temp->value);
	}
	
	//kalau misal tree cuman ada 1 node
	if(!curr){
		return NULL;
	}
	
	//update tinggi parent parentnya(anchestor)
	curr->height = max(getHeight(curr->left), getHeight(curr->right) + 1);
	
	
	//cari balance factor
	int balance = getBalance(curr);

	//cek apakah tree ini ga seimbang\
	//RR imbalance
	if(balance < -1 && getBalance(curr->right) <= 0){
		//Left Rotate
		return leftRotate(curr);
	}
	//RL imbalance
	else if(balance < -1 && getBalance(curr->right) > 0){
		//Right rotate anak kanannya
		curr->right = rightRotate(curr->right);
		//left rotate
		return leftRotate(curr);
	}
	//LL imbalance
	else if(balance > 1 && getBalance(curr->left) >= 0){
		//Right Rotate
		return rightRotate(curr);
	}
	//LR imbalance
	else if(balance > 1 && getBalance(curr->left) < 0){
		//Left rotate anak kirinya
		curr->left = leftRotate(curr->left);
		//Right rotate
		return rightRotate(curr);
	}
	return curr;
}

void deleteAllNode(Node *curr){
	if(!curr){
		return;
	}
	deleteAllNode(curr->left);
	deleteAllNode(curr->right);
	free(curr);
	curr=NULL;
}

int main(){
    Node *root = NULL;
    root = insert(root,10);
    root = insert(root,20);
    root = insert(root,30);
    root = insert(root,40);
    root = insert(root,50);
    root = insert(root,25);
    root = insert(root,28);

    PreOrder(root);
	
	root = deleteNode (root, 50);
	printf("\n");
	printf("After Deletion: \n");
	PreOrder(root);

}

