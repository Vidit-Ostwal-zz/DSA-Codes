/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
  ListNode* addlinkedlist(ListNode* l1, ListNode* l2, int car_for)
  {
    if (l1 == NULL)
    {
      if (car_for == 0)
         return l2;
      else
        return addlinkedlist(new ListNode(car_for),l2,0);
    }
     
    
    if (l2 == NULL)
    {
     if (car_for == 0)
         return l1;
      else
        return addlinkedlist(l1,new ListNode(car_for),0);
    }
   
  
  ListNode* head = NULL;
  int curr_dig = l1->val + l2->val + car_for;
  head = new ListNode(curr_dig % 10);
  head -> next = addlinkedlist(l1 -> next, l2 -> next,curr_dig/10);
  
  return head;
}
  
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return addlinkedlist(l1,l2,0);
    }
};