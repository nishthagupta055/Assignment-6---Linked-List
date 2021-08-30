struct ListNode* reverseBetween(struct ListNode* head, int left, int right){

      struct ListNode *root = head ,*lt,*rt,*pre,*cur,*nxt; 
    if(head == NULL)
        return head;
    if(head -> next == NULL)
        return head;
    long long i = 0,handled = 0;
    struct ListNode* extra = (struct ListNode*) malloc (sizeof (struct ListNode));
    if(left == 1)
    {
        handled = 1; 
        extra -> next = head;
        extra -> val = 0;
        head = extra;
        left++;
        right++;
    }
    pre = NULL;
    cur = head; 
    nxt = head->next;
    lt = head;
    rt = head;
    
    while(cur != NULL)
    {
       ++i;
       if(i == left-1)
          lt = cur;
       if(i > left && i <= right)
       {
          cur -> next = pre;
       }
       if(i == right)
       {
          lt -> next -> next = nxt;
          lt -> next = cur;  
            
       }  
        
       pre = cur; 
       cur = nxt;
       if(nxt != NULL)
          nxt = cur -> next;
    }

   if(handled)
   {
       head=head -> next;
   }
   return head; 
}