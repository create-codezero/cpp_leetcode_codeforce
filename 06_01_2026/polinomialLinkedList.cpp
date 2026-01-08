#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct terms{
	int coeff;
	int power;
	struct terms* next;
};

void printLinkedList(struct terms* h){
	while(h != NULL){
		if(h->next == NULL){
			cout << h->coeff << "x^" << h->power;
		}else{
			cout << h->coeff << "x^" << h->power << "+ ";
		}
		
		h=h->next;
	}
	cout << endl;
}

void addPolynomials(struct terms* p1, struct terms* p2){
	struct terms* addedHead = NULL;
	struct terms* addedTail = NULL;
	while(p1!=NULL || p2!=NULL){
		struct terms* newTerm = (struct terms*) malloc(sizeof(struct terms));
		newTerm->next =  NULL;
		
		
		if(p1->power > p2->power){
			newTerm->power = p1->power;
			newTerm->coeff = p1->coeff;
		}else if(p1->power < p2->power){
			newTerm->power = p2->power;
			newTerm->coeff = p2->coeff;
		}else{
			newTerm->power = p1->power;
			newTerm->coeff = p1->coeff + p2->coeff;
		}
		
		if(addedHead == NULL){
			addedHead = addedTail = newTerm;
		}else{
			addedTail->next = newTerm;
			addedTail = addedTail->next;
		}
		
		if(p1->power > p2->power){
			p1 = p1->next;
		}else if(p1->power < p2->power){
			p2 = p2->next;
		}else{
			p1 = p1->next;
			p2 = p2->next;
		}	
	}
	
	printLinkedList(addedHead);
}


int main(){
	int n;
	cout << "Enter the total nubmer of the terms:";
	cin >> n;
	cout << endl;
	
	cout << "Enter the values of coeff and power (space seperated) for each terms one by one [for the first Polynomial] : ";
	struct terms* pol1Head = NULL;
	struct terms* temp1Head = NULL;
	int t = n;
	while(t--){
		int c,p;
		cin >> c >> p;
		struct terms* newTerm = (struct terms*) malloc(sizeof(struct terms));
		newTerm->coeff = c;
		newTerm->power = p;
		if(pol1Head == NULL){
			newTerm->next = NULL;
			pol1Head = temp1Head = newTerm;
		}else{
			newTerm->next = NULL;
			temp1Head->next = newTerm;
			temp1Head = temp1Head->next;
		}
	}
	
	cout << "Enter the values of coeff and power (space seperated) for each terms one by one [for the second Polynomial] : ";
	struct terms* pol2Head = NULL;
	struct terms* temp2Head = NULL;
	
	t = n;
	while(t--){
		int c,p;
		cin >> c >> p;
		struct terms* newTerm = (struct terms*) malloc(sizeof(struct terms));
		newTerm->coeff = c;
		newTerm->power = p;
		if(pol2Head == NULL){
			newTerm->next = NULL;
			pol2Head = temp2Head = newTerm;
		}else{
			newTerm->next = NULL;
			temp2Head->next = newTerm;
			temp2Head = temp2Head->next;
		}
	}
		
	cout << endl;
	
	printLinkedList(pol1Head);
	printLinkedList(pol2Head);
	
	cout << endl;
	cout << "Now adding both the Polynomails:" << endl;
	
	addPolynomials(pol1Head, pol2Head);
	
}