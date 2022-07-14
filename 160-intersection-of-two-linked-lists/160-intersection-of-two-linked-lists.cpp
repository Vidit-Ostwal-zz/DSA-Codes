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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
      
      ListNode* A = headA;
      ListNode* B = headB;
      
      // if ()
      if (headA == NULL || headB == NULL)
        return NULL;
      
      while ( A!= B && A != NULL && B != NULL)
      {
        A = A -> next;
        B = B -> next;
        
        if (A == B)
          return A;
        
        if (A == NULL)
          A = headA;
        
        if (B == NULL)
          B = headB;
      }
      
      if (A != NULL)
        return A;
      
      return NULL;
    }
};