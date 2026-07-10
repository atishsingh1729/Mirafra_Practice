#include<stdio.h>
#include<stdlib.h>


typedef struct node{
	int data;
	struct node *next;
	struct node *prev; 	
}node_t;


node_t* insertAtEnd(node_t* head,int val){

	node_t* newNode = (node_t*)malloc(sizeof(node_t));
	
	if(newNode == NULL)
	return head;

	newNode->data = val;
	newNode->next=NULL;
	newNode->prev=NULL;	

	
	if(head == NULL)
	return newNode;
	
	node_t *temp = head;
	
	while(temp->next != NULL){
		temp=temp->next;
	} 
	temp->next = newNode;
	newNode->prev = temp;	

	return head;
}

node_t* reverse(node_t* head){
	node_t* curr = head;
	node_t* temp=NULL;

	while(curr != NULL){
		temp=curr->next;//save the next node address to temp
		curr->next=curr->prev;//swap
		curr->prev = temp;//swap
		head=curr;//save the curr as head
		curr=temp;
	}

	return head;
}



void printList(node_t *head){
	node_t *temp = head;
	if(head == NULL)
	return;

	printf("NULL-> ");

	while(temp != NULL){
		printf("%d -> ",temp->data);
		temp=temp->next;
	}
	printf("NULL\n");
	
}

int main(){

	node_t *head = NULL;

	head = insertAtEnd(head,1);
	head = insertAtEnd(head,2);
	head = insertAtEnd(head,3);
	printList(head);
	
	head = reverse(head);
	
	printList(head);

	return 0;
}
