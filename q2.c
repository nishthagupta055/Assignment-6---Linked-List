#include<stdio.h>
#include <stdlib.h>
struct queue_node{
	int data ;
	struct queue_node *next; 
};
struct queue_node *head = NULL;
struct queue_node *tail = NULL;
void enqueue(int val)
{
	struct queue_node *temp = (struct queue_node*)malloc(sizeof(struct queue_node));
        temp -> data = val;
    if(head == NULL)
	{
	   head = temp;
	   tail = temp;
	   temp -> next = NULL;
	}
	else
	{
	   tail -> next = temp;
	   tail = temp;
	   temp -> next = NULL;
	}
	  
}
int dequeue()
{ 
	if(head == NULL)
	return -1;
	int element = -1;
	if(tail == head)
	{
		element = tail -> data;
		tail = NULL;
		head = NULL;
	}
	else
	{
		struct queue_node *removed = head;
		element = head -> data;
		head=head -> next;
		free(removed);
		
	}
	return element; 
}
int peek()
{
	
	if(head == NULL)
	return -1;
	return head -> data;
}
int is_empty()
{
	if(head == NULL)
	return 1;
	else
	return 0;
}
int main()
{
	enqueue(1);
	enqueue(2);
	struct queue_node *print=head;
	while(print != NULL)
	{
		printf("%d\n",print -> data);
		print=print -> next;
	}
	printf("Peek element is %d\n",peek());
	dequeue();
        print = head;
	while(print != NULL)
	{
		printf("%d\n",print -> data);
		print = print -> next;
	}
	
	if(is_empty())
         printf("YES\n");
	else
	 printf("NO\n");
	 
	dequeue();
	
	if(is_empty())
         printf("YES\n");
	else
	 printf("NO\n");
	 
	enqueue(1);
	print = head;
	while(print != NULL)
	{
		printf("%d\n",print -> data);
		print = print -> next;
	}
	
        printf("Peek element is %d\n",peek());
}