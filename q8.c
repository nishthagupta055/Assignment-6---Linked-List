struct ListNode* merger(struct ListNode* list1, struct ListNode* list2)
{   
    if(list1==NULL)
        return list2; 
    else if(list2==NULL)
        return list1;
    
    if(list1->val>=list2->val)
    {
        list2->next=merger(list1,list2->next);
        return list2; 
    }
    else
    {
        list1->next=merger(list1->next,list2);
        return list1;
    }
  
}
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    struct LisNode* merged_list=merger(l1,l2);
    return merged_list;
}