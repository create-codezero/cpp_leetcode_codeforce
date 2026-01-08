#include<stdio.h>

void saveInStack(int* s, int v, int* t, int n){
	
	if(*t==n-1){
		printf("Stack is full.\n");
		return;
	}
	(*t)++;
	s[*t] = v;
}

void printStack(int* s, int t){
	while (t >= 0){
		printf("|  %d  |\n",s[t]);
		
		t--;
	}
}

int main(){
	int n;
	printf("Enter the Total Number of Element in the Stack:");
	scanf("%d",&n);
	
	int stack[n];
	
	printf("\nEnter the Number of the Elements you want to save in the Stack");
	
	int k;
	scanf("%d",&k);
	
	int t = -1;
	printf("\nEnter the Values one by one: ");
	while(k--){
		int v;
		scanf("%d",&v);
		
		saveInStack(stack,v,&t,n);
	}
	
	printf("Printing the Stack Now:");
	printStack(stack,t);
	
	
	
}