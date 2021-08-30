struct ListNode* deleteDuplicates(struct ListNode* head){
    int negative[101] , positive[101];
    for(int i = 0; i < 101; ++i)
    {
        negative[i] = 0;
        positive[i] = 0;
    }
    
    struct ListNode *root =head; 
    struct ListNode *answer=head;
    if(head==NULL)
        return head; 
    while(root!=NULL)
    {
        if(root->val>=0)
        {
            positive[root->val]++;
        }
        else
        {
            negative[-root->val]++;
        }
        
        root=root->next;
    }
    root=head;
    while(root!=NULL)
    {
     
        root=root->next;
        if(root==NULL)
        break; 
        if(root->val>=0)
        {
            if(positive[root->val]==1)
            {
                answer->next=root;
                answer=answer->next;
            }
        }
        if(root->val<0)
        {
            if(negative[-root->val]==1)
            {
                answer->next=root;
                answer=answer->next;
            }
        }
    }
    answer->next=NULL;
    while(head!=NULL)
    {    
         if(head->val>=0)
         {
            
            if(positive[head->val]>1)
            {
                head=head->next;
            }
            else
            break;
         }
         else if(head->val<0)
         {
            if(negative[-head->val]>1)
            {
               head=head->next;
            }
            else
            break;
         }
    }
    return head; 
}