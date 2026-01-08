#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Node {
	struct Node* prev;
	int val;
	struct Node* next;
};

void printDLinkedList(struct Node* h){
	while(h != NULL){
		cout << h->val << ", " ;
		h = h->next;
	}
	
	cout << endl;
}

void printRevDLinkedList(struct Node* h){
	while(h != NULL){
		cout << h->val << ", " ;
		h = h->prev;
	}
	
	cout << endl;
}

void deleteNode(struct Node*& head, int v){
	struct Node* h = head;
	while(h!=NULL){
		if(h->val == v){
			// delete the node here
			struct Node* temp = h;
			
			h->prev->next = h->next;
			h->next->prev = h->prev;
			
			free(temp);
			break;
		}
		
		h = h->next;
	}
}


int main(){
	
	int n;
	cout << "Enter the Number of the Elements in the Doubly Linked List you want to add : " << endl;
	cin >> n;
	
	
	struct Node* head = NULL;
	struct Node* tail = NULL;
	
	cout << "Enter the Values One by One: " << endl;
	while(n--){
		int v;
		cin >> v;
		struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
		newNode->val = v;
		
		if(head == NULL){
			newNode->prev = NULL;
			newNode->next = NULL;
			
			head = tail = newNode;
		}else{
			newNode->prev = tail;
			newNode->next = NULL;
			tail->next = newNode;
			
			tail = tail->next;
		}
	}
	
	printDLinkedList(head);
	
	cout << "Enter The value you want to delete: " ;
	int delVal;
	cin >> delVal;
	deleteNode(head, delVal);
	
	cout << endl;
	cout << "After deletion the Linked list is : ";
	printDLinkedList(head);
	
	cout << "Reverse Doubly Linked List: " ;
	printRevDLinkedList(tail);
	
	
	return 0;
}