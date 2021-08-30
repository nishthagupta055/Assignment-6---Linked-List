#include<stdio.h>
#include<stdlib.h>

struct stack
{
    int data;
    struct stack *next;
    	
};

void push(struct stack **head,int val)
{
   
    
    struct stack *temp_stack=(struct stack*)malloc(sizeof(struct stack));
    
    temp_stack->data=val;
    temp_stack->next=NULL;
    if(head!=NULL)
    temp_stack->next=*head;
    *head=temp_stack;
}
int pop(struct stack **head)
{
    
    struct stack *temp_node=*head;
    
    if(temp_node==NULL)
    return -1;
    int val=temp_node->data;
    temp_node=*head;
   
    struct stack *head2=*head;
    head2=head2->next;
    *head=head2;
    
    temp_node->next=NULL;
    free(temp_node);
    

    return val;
}
int peek(struct stack *head)
{
    if(head==NULL)
    return -1;
    else
    return head->data;
}
int is_empty(struct stack *head)
{
    
    
    if(head==NULL)
    return 1;
    else
    return 0;
}


int main() {
    struct stack *node=NULL;
    push(&node,1);
    push(&node,2);
    
    
    printf("Elements of LinkList :\n");
    struct stack* answer=node;
    while(answer!=NULL)
    {
        printf("%d\n",answer->data);
        answer=answer->next;
    }
    
    printf("Peek Element is %d\n",peek(node));
    if(is_empty(node))
    printf("YES\n");
    else
    printf("NO\n");
    
    pop(&node);
    pop(&node);
    
    if(is_empty(node))
    printf("YES\n");
    else
    printf("NO\n");
    push(&node,1);
    push(&node,2);
    printf("Elements of LinkList :\n");
    answer=node;
    while(answer!=NULL)
    {
        printf("%d\n",answer->data);
        answer=answer->next;
    }
    
    printf("Peek Element is %d\n",peek(node));
    return 0;
}