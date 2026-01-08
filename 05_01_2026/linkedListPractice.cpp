#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct node{
	int val;
	struct node* next;
};

void printLinkedList(struct node* h){
	while(h != NULL){
		cout << h->val << ", ";
		h= h->next;
	}
	cout << endl;
}

void reverseLinkedList(struct node* h){
	struct node* temp = NULL;
	
	while(h != NULL){
		struct node* revNew = (struct node*) malloc(sizeof(struct node));
		
		revNew->val = h->val;
		
		if(temp == NULL){
			revNew->next = NULL;
			temp = revNew;
		}else{
			revNew->next = temp;
			temp = revNew;
		}
		
		h = h->next;
	}
	printLinkedList(temp);
	
	
}
// use the same address with & while deleting
void deleteNode(struct node*& head, int v) {
    struct node* h = head;
    struct node* prevNode = NULL;

    while (h != NULL) {
        if (h->val == v) {
            cout << "Deleting the node with value: " << v << endl;

            if (prevNode == NULL) {
                head = h->next;
            } else {
                prevNode->next = h->next;
            }

            free(h);
            return;
        }

        prevNode = h;
        h = h->next;
    }
}

int main(){
	cout << "Enter the total Number of the nodes you want to create : " << endl;
	
	int n;
	cin >> n ;
	
	struct node* head = NULL;
	struct node* temp = head; 
	
	while(n--){
		int v;
		cin >> v;
		
		struct node * newNode = (struct node * ) malloc(sizeof(struct node));
		
		newNode->val = v;
		newNode->next = NULL;
				
		if(head == NULL){
			temp = head = newNode;
		}else{
			temp->next = newNode;
			temp = temp->next; 
		}
			
	}
	
	printLinkedList(head);
	
	reverseLinkedList(head);
	
	int delVal;
	cout << "Enter the value you want to delete: " << endl ;
	cin >> delVal;
	
	deleteNode(head, delVal);
	
	printLinkedList(head);
	
	return 0;
	
}