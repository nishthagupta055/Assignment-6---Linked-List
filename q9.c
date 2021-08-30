struct ListNode* rotateRight(struct ListNode* head, int k){
    if(head==NULL||k==0)
        return head; 
     struct ListNode* root = head; 
    struct ListNode* begin = head; 
     int size = 0;
    while(root!=NULL)
    {
        root=root->next;
        size++;
    }
    k%=size;
    if(k==0)
        return head;
    int idx=0;
    struct ListNode* end = head; 
    root=head;
    while(root!=NULL)
    {
        
    idx++;   
    if(idx==size-k)
    {
       
        end=root;
        head=root->next;
    }   
    if(root->next==NULL)
    {
        root->next=begin;
        break; 
    }
    root=root->next;
        
    }
    
    end->next=NULL;
    return head;
}