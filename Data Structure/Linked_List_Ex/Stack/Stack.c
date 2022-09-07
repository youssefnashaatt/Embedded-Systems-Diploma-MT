#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node* next;
};

struct node* head = NULL;
struct node* current = NULL;


int peak(void)
{
	if(head == NULL)
	{
		printf("Error..Stack is empty");
		return 0;
	}

	else
		return head->data;
}

void push(int data)
{
	struct node* link = (struct node*)malloc(sizeof(struct node));
	link->data = data;

	link->next = head;
	head = link;

	printf("%d is pushed\n", data);
}

void pop(void)
{
	if(head == NULL)
	{
		printf("Stack is empty\n");
		return;
	}

	else if(head->next == NULL)
	{
		printf("%d is popped, stack now is empty!\n", head->data);
		free(head);
		head = NULL;
		return;
	}

	printf("%d is popped\n", head->data);
	head = head->next;
	free(head);
}




int main(void)
{
	push(10);
	printf("The peak of stack is %d\n", peak());
	push(20);
	push(30);
	printf("The peak of stack is %d\n", peak());
	pop();
	printf("The peak of stack is %d\n", peak());
	pop();
	pop();
	pop();

}
