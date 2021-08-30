struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode* root = head; =
    int size=0;
    while(root!=NULL)
    {
        root=root->next;
        size++;
    }
    root=head; 
    int idx=0;
    while(root!=NULL)
    {
        idx++;
        if(idx==(size-n))
        {
            if(size-n==size-1)
                root->next=NULL;
            else
                root->next=root->next->next;
        }
        root=root->next; 
    }
    if(size==n)
    {
        head=head->next;
    }
    return head;
}