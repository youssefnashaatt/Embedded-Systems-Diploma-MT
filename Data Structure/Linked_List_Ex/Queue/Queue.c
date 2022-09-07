#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node* next;
};

struct node* head = NULL;
struct node* current = NULL;

int first_of_queue(void)
{
	return head->data;
}

void entering_queue(int data)
{
	struct node* link = (struct node*)malloc(sizeof(struct node));
	link->data = data;

	printf("%d entered queue\n", link->data);
	current = head;

	if(current == NULL)
	{
		head = link;
		head->next = NULL;
		return;
	}

	while(current->next != NULL)
	{
		current = current->next;
	}

	link->next = NULL;
	current->next= link;
}


void leaving_queue(void)
{
	if(head == NULL)
	{
		printf("Queue is empty!\n");
		return;
	}

	else if(head->next == NULL)
	{
		printf("%d left queue, queue now is empty\n", first_of_queue());
		free(head);
		head = NULL;
		return;
	}

	printf("%d left queue\n", first_of_queue());
	head = head->next;
	free(head);
}



int main(void)
{
	entering_queue(10);
	printf("First of queue is %d\n", first_of_queue());
	entering_queue(20);
	entering_queue(30);
	printf("First of queue is %d\n", first_of_queue());
	leaving_queue();
	printf("First of queue is %d\n", first_of_queue());
	leaving_queue();
	leaving_queue();
	leaving_queue();

}
