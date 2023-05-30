#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
struct node *head=NULL;
struct node *end = NULL;
void insert(int val)
{
	struct node *newNode = (struct node*)malloc(sizeof(struct node));
	newNode->data=val;
	newNode->next=NULL;
	if(head==NULL){
		head=end=newNode;
	}
	else{
		end->next=newNode;
		end=newNode;
	}
}
void display()
{
	struct node *i;
	for(i=head;i!=NULL;i=i->next)
	{
		printf("%d %u\n",i->data,i);
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	while(n--){
		int val;
		scanf("%d",&val);
		insert(val);
	}
	display();
}
