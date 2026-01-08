#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct Node {
	int val;
	struct Node* next;
};

void printLinkedList(struct Node* h){
	struct Node* temp = h;
	cout << h->val << ", ";
	h= h->next;
	while(h != NULL){
		if (temp == h)
			break;
		cout << h->val << ", ";
		h= h->next;
	}
	cout << endl;
}

int main(){
	int n;
	cout << "Enter the Number of the Elements: ";
	cin >> n;
	
	struct Node* head = NULL;
	struct Node* tail = NULL;
	
	cout << endl;
	cout << "Enter the Elements One by One: ";
	while (n--){
		int v;
		cin >> v;
		
		struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
		
		newNode->val = v;
		
		if(head == NULL){
			newNode->next = NULL;
			head = tail = newNode;
			head->next = head;
			
		}else{
			newNode->next =  head;
			tail->next = newNode;
			tail = tail->next;
		}
		
	}
	
	printLinkedList(tail);
}

