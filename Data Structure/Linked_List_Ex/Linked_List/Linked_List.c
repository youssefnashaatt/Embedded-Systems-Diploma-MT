#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node* next;
};


struct node* head = NULL;
struct node* current = NULL;


void insert_at_first(int data);
void insert_at_last(int data);
void print_linked_list(void);
int get_linked_list_size(void);
void delete_node_at_first(void);
void delete_node_at_last(void);
void insert_at_pos(int data, int pos);
void print_data_at_middle(void);
void print_fifth_from_end(void);
int sum_of_linked_list(void);
int max_of_linked_list(void);
void insert_at_ascending(int data);



int main(void)
{
	insert_at_first(30);
	insert_at_first(20);
	insert_at_first(10);

	print_linked_list();

	insert_at_last(40);
	insert_at_last(50);
	insert_at_last(60);
	insert_at_last(70);

	print_linked_list();

	printf("\nLinked List Size: %d", get_linked_list_size());

	delete_node_at_first();
	delete_node_at_last();

	printf("\n");

	print_linked_list();

	printf("\nLinked List Size: %d\n", get_linked_list_size());


	insert_at_pos(35,2);
	print_linked_list();
	insert_at_pos(5,0);
	print_linked_list();
	insert_at_pos(15,1);
	print_linked_list();

	printf("\n");

	printf("\nLinked List Size: %d", get_linked_list_size());

	print_linked_list();
	print_data_at_middle();

	printf("\n");

	print_fifth_from_end();

	printf("\n\nSum of linked list is %d\n", sum_of_linked_list());

	insert_at_ascending(25);
	print_linked_list();

	printf("\nMax of linked list is %d\n", max_of_linked_list());

	insert_at_pos(90,4);
	print_linked_list();
	printf("\nMax of linked list is %d\n", max_of_linked_list());

	return 0;

}


void insert_at_first(int data)
{
	struct node* link = (struct node*)malloc(sizeof(struct node));
	link->data = data;
	link->next = head;
	head = link;
}

void insert_at_last(int data)
{
	struct node* link = (struct node*)malloc(sizeof(struct node));
	link->data = data;
	link->next = NULL;
	current = head;

	if(current == NULL)
	{
		head = link;
		return;
	}

	while(current->next != NULL)
	{
		current = current->next;
	}

	current->next = link;
}


void print_linked_list(void)
{
	current = head;
	printf("\nhead");

	while(current != NULL)
	{
		printf(" -> %d", current->data);
		current = current->next;
	}
}


int get_linked_list_size(void)
{
	int count = 0;
	current = head;

	while(current != NULL)
	{
		count++;
		current = current->next;
	}

	return count;
}


void delete_node_at_first(void)
{
	if(head == NULL)
		return;

	current = head;
	head = head->next;
	free(current);
}

void delete_node_at_last(void)
{

	if(head == NULL)
		return;

	struct node* tracker;
	tracker = head;
	current = head->next;

	while(current->next != NULL)
	{
		current = current->next;
		tracker = tracker->next;
	}

	tracker->next = NULL;
	free(current);
}


void insert_at_pos(int data, int pos)
{
	struct node* link = (struct node*)malloc(sizeof(struct node));
	link->data = data;

	if(pos == 0)
	{
		link->next = head;
		head = link;
	}

	else if(pos == 1)
	{
		link->next = head->next;
		head->next = link;
	}


	else
	{

		int current_pos = 1;
		current = head;

		while(pos > current_pos)
		{
			current = current->next;
			current_pos++;
		}

		link->next = current->next;
		current->next = link;
	}
}


void print_data_at_middle(void)
{
	if(head == NULL)
		return;

	else if(head->next == NULL)
		printf("Data at middle is %d", head->data);

	struct node* printer;
	printer = head;
	current = head;


	while((current->next != NULL) && (current->next->next != NULL))
	{
		current = current->next->next;
		printer = printer->next;
	}

	if(current->next == NULL)
	{
		printf("\n\nData at middle is %d", printer->data);
	}

	else
	{
		printf("\n\nData at middle are %d and %d", printer->data, printer->next->data);
		printf("\nTheir average is %.1f", (float)(printer->data + printer->next->data) / 2.0);
	}

}


void print_fifth_from_end(void)
{
	current = head;

	while(current->next->next->next->next->next != NULL)
	{
		current = current->next;
	}

	printf("Fifth element from the end is %d", current->data);
}


int sum_of_linked_list(void)
{
	int sum = 0;
	current = head;

	while(current != NULL)
	{
		sum += current->data;
		current = current->next;
	}

	return sum;
}

int max_of_linked_list(void)
{
	int max;
	current = head;
	max = current->data;
	current = current->next;

	while(current != NULL)
	{
		if(current->data > max)
			max = current->data;

		current = current->next;
	}

	return max;
}


void insert_at_ascending(int data)
{
	struct node* link = (struct node*)malloc(sizeof(struct node));
	link->data = data;
	current = head;

	while(link->data > current->next->data)
	{
		current = current->next;
	}

	link->next = current->next;
	current->next = link;

}
