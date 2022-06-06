/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
  // Change the values to negative and then again traverse the whole thing, first negative value will be the answer
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
      ListNode* A = headA;
      ListNode* B = headB;
      
      if (A == NULL || B == NULL)
        return NULL;
      
      while (A != B && A != NULL && B != NULL)
      {
        A = A -> next;
        B = B -> next;
        
        if (A == B)
          return A;
        
        if (!A)
          A = headB;
        
        if (!B)
          B = headA;
      }
      
      if (!A && !B)
        return NULL;
      
      return A;
    }
};