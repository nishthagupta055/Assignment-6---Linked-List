struct stack{
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

bool isPalindrome(struct ListNode* head){
    
    struct stack *node=NULL;
    if(head==NULL)
        return true ;
    if(head->next==NULL)
        return true; 
    struct ListNode* root= head;
    int size = 0;
    
    while(root!=NULL)
    {
        
        size++;
        root=root->next; 
    }
    root=head;
    
    int i =0;
    
    while(root!=NULL)
    {
         if(i<size/2)
        {
            push(&node,root->val);
        }
         else if(i>=(size+1)/2)
        {
            if(pop(&node)!=root->val)
            {
                return false; 
            }
        }
        i++;
        root=root->next; 
    }
    return true; 
    
    

}
