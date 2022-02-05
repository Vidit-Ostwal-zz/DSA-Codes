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
public:
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

  ListNode* reverse (ListNode* l1)
  {
    ListNode* prev = NULL;
    ListNode* pres = l1;
    ListNode* futu = l1 -> next ;
    
    while (pres != NULL)
    {
      pres -> next = prev;
      prev = pres;
      pres = futu;
      if (futu != NULL)
        futu = futu -> next;
    }
    return prev;
    
  }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverse(l1);
      l2 = reverse(l2);
      return reverse(addlinkedlist(l1,l2,0));
    }
};