#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next,*prev;
};
typedef struct node Node;
Node* head=NULL;
Node* tail=NULL;
Node* createNode(int val)
{
	Node* newNode = (Node *)malloc(sizeof(Node*));
	newNode->data=val;
	newNode->next=newNode->prev=NULL;
	return newNode;
}
void insertAtEnd(int val)
{
	Node *newNode = createNode(val);
	if(head==NULL){
		head=tail=newNode;
	}
	else{
		tail->next=newNode;
		newNode->prev=tail;
		tail=newNode;
	}
}
void insertAtBegin(int val)
{
	Node *newNode = createNode(val);
	if(head==NULL){
		head=tail=newNode;
	}
	else{
		head->prev=newNode;
		newNode->next=head;
		head=newNode;
	}
}
void deleteAtBegin()
{
	Node*temp = head->next;
	temp->prev=NULL;
	free(temp->prev);
	head=temp;
}
void deleteAtEnd()
{
	Node*temp = tail->prev;
	temp->next=NULL;
	free(temp->next);
	tail=temp;
}
void rev()
{
	Node *i;
	for(i=tail;i;i=i->prev){
		printf("%d ",i->data);
	}
}
void dis()
{
	Node *i;
	for(i=head;i;i=i->next){
		printf("%d ",i->data);
	}
}
int search(int key){
	Node *i=head;
//	for(i=head;i;i=i->next){
//		if(i->data==key){
//			return 1;
//		}
//	}
	while(i){
		if(i->data==key){
			return 1;
		}
		i=i->next;
	}
	return 0;
}
int main()
{
	int n;
	scanf("%d",&n);
	while(n--)
	{
		int val;
		scanf("%d",&val);
		insertAtEnd(val);
	}
	dis();
	printf("\n");
	rev();
	printf("\n");
	int val;
	scanf("%d",&val);
	printf("\n");
	if(search(val)){
		printf("Element found....");
	}
	else{
		printf("Element not found....");
	}
	printf("\n");
	deleteAtBegin();
	deleteAtEnd();
	dis();
}
	
	
