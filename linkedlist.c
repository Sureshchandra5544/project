#include<stdio.h>
#include<stdlib.h>
struct node 
{
	int data;
	struct node* next;
};

void printlist(struct node* n)
{
	while (n != NULL)
	{
		printf("%d\n",n -> data);
		n = n -> next;
	}
}
void push(struct node** head, int new_data)
{
	struct node* new_node = (struct node*)malloc(sizeof(struct node));
			new_node -> data = new_data;
		       new_node -> next = (*head);
			(*head) = new_node;
}		
void insertafter(struct node* prev_node, int new_data)
{
	if(prev_node == NULL)
	{
		printf(" The previous node cannot be null \n");
		return;
	}
	struct node* new_node = (struct node*)malloc(sizeof(struct node));
			new_node -> data = new_data;
			new_node -> next = prev_node -> next;
			prev_node -> next = new_node;
}
int main()
{
	struct node* head = NULL;
	struct node* second = NULL;
	struct node* third= NULL;

	head = (struct node*)malloc(sizeof(struct node));
	second = (struct node*)malloc(sizeof(struct node));
	third = (struct node*)malloc(sizeof(struct node));
	 
	head -> data = 1;
	head -> next = second;
//	printf("First node\n");

	second -> data = 2;
	second -> next = third;
//	printf("Second node\n");

	third -> data= 3;
	third -> next = NULL;
//	printf("Third node\n");
	printlist(head);
	printf("\n");
	push(&head,5);
	printlist(head);
	printf("\n");
	insertafter(head -> next,8); 
	printlist(head);
	return 0;

}
