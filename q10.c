struct ListNode *detectCycle(struct ListNode *head) {
        struct ListNode * turtle, *hair;
        if(head == NULL)
            return false;
        if(head -> next==NULL)
            return false;
        
        turtle = head;
        
        hair = head; 
       
        while(hair!=NULL&&hair->next!=NULL)
        {
            hair = hair -> next -> next;
            turtle = turtle -> next;
            if(turtle==hair)
            {
             turtle = head;
         while(turtle != hair)
             {
	         turtle = turtle -> next;
		 hair = hair -> next;
	     }
	        return turtle;
            }
        }
        return NULL;
}