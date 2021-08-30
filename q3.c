#include<stdio.h>
#include<stdlib.h>
struct node
{
        int data;
	struct node *next;
};
struct node *head = NULL , *tail = NULL;
void enqueue_head(int value)
{
	struct node *new_node=(struct node*)malloc(sizeof(struct node));
	new_node -> next = NULL;
	new_node -> data=value;
	if(head == NULL)
	{
		head = new_node;
		tail = new_node;
	}
	else
	{
	        new_node -> next = head;
	        head = new_node;
	}
}

void enqueue_tail(int value)
{
	
	struct node *new_node=(struct node*)malloc(sizeof(struct node));
	new_node -> next = NULL;
	new_node -> data = value;
	
	if(tail == NULL)
	{
		head = new_node;
		tail = new_node;
	}
	
	else
	{
		tail -> next = new_node;
		tail = tail -> next;
	}
}

int dequeue_head()
{
	if(head == NULL)
	return -1;
	if(head == tail)
	{
		tail = NULL;
	}
	
        int val = head -> data;
        struct node *removed=head;
	head = head -> next;
        free(removed);
        return val; 
}

int dequeue_tail()
{
	if(tail == NULL)
	return -1;
	int val = tail -> data;
	if(head == tail)
	{
	    head = NULL;
	    struct node *removed = tail;
            tail = tail -> next;
            free(removed);
            return val; 
	}
	
	struct node *pointer = head;
		while(pointer -> next != tail)
	{
		pointer = pointer -> next;
	}
	struct node *removed = tail;
	tail = pointer;
	tail -> next = NULL;
	free(removed);
	return val ;
	
}

int peek_head()
{
	if(head == NULL)
	return -1;
	return head -> data;
}

int peek_tail()
{
	if(tail == NULL)
	return -1;
	return tail -> data;
}

int is_empty()
{
	if(head == NULL && tail == NULL)
	return 1;
	else
	return 0;
}

int is_present(int value)
{
	struct node *checker = head;
		while(checker != NULL)
	{
		if(checker -> data == value)
		return 1;
		checker = checker -> next;
	}
	return 0;
}

int main()
{
	
	enqueue_head(1);
	enqueue_head(2);
	enqueue_tail(3);
	enqueue_tail(4);
	struct node *printer =head;
	
	while(printer != NULL)
	{
		printf("%d\n", printer->data);
		printer = printer -> next;
	}
	printf("head value is: %d\n",head -> data);
	printf("tail value is: %d\n",tail -> data);
	dequeue_head();
	dequeue_tail();
	printer = head;
	while(printer != NULL)
	{
		printf("%d\n",printer -> data);
		printer = printer -> next;
	}
	printf("head value is: %d\n",head -> data);
	printf("tail value is: %d\n",tail -> data);
	if(is_present(3))
	{
		printf("Yes 3 is present\n");
	}
	else
	{
		printf("NO 3 is not present\n");
	}
	if(is_present(2))
	{
		printf("Yes 2 is present\n");
	}
	else
	{
		printf("No 2 is not present\n");
	}		
	if(is_empty())
	{
		printf("Yes deque is empty\n");
	}
	else
	{
		printf("No deque is not empty\n");
	}	
	dequeue_head();
	dequeue_head();
	if(is_empty())
	{
		printf("Yes deque is empty\n");
	}
	else
	{
		printf("No deque is not empty\n");
	}	
}