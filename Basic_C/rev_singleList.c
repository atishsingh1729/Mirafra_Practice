#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node* next;	
}node_t;


node_t* insertAtEnd(node_t* head,int val){

	node_t *newNode = (node_t*)malloc(sizeof(node_t));
	
	if(newNode == NULL)
		return head;

	newNode->data=val;
	newNode->next=NULL;

	if(head == NULL)
	return newNode;


	node_t *temp = head;
	while(temp->next != NULL){
		temp=temp->next;
	}
	temp->next = newNode;	
	return head;
}


void printList(node_t *head){

	if(head == NULL)
	return;
	
	node_t *temp = head;
	while(temp != NULL){
		
		printf("%d -> ",temp->data);
		temp = temp->next;
	}
	printf("NULL\n");
}

node_t* reverse(node_t* head){

	node_t* cur = head;
	node_t* prev = NULL;
	node_t* next = NULL;

	while(cur != NULL){
		next = cur->next;//ready the next node by loading it to next variable
		cur->next = prev;//reverse the direction by making the next node to point to the prev node
		
		prev = cur;//increment the prev node pointer
		cur = next;//increment the current node pointer
		
	}
	return prev;//since previous will be the new head 
}

int main(){


	node_t* head = NULL;

 	head = insertAtEnd(head,1);
 	head = insertAtEnd(head,2);
 	head = insertAtEnd(head,3);
 	head = insertAtEnd(head,4);
 	head = insertAtEnd(head,5);
 	head = insertAtEnd(head,6);
 	head = insertAtEnd(head,7);

	printf("Original List : ");
	printList(head);
	
	head = reverse(head);
	printf("After Reversal :");
	printList(head);


	return 0;

}
