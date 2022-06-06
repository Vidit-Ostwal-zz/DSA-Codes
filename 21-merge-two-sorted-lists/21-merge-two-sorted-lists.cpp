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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
      
      // Base Cases
      if (list1 == NULL)
          return list2;
      
      if (list2 == NULL)
        return list1;
      
      // Making Arrangments such that list1 head is the head;
      ListNode* A = list1;
      ListNode* B = list2;
      ListNode* temp;
      ListNode* Head;
      if (A-> val > B-> val)
      {
        temp = A;
        A = B;
        B = temp;
      }
      // Now smallest is ListNode A
      temp = A;
      Head = temp;
      A = A -> next;
      while (A && B)
      {
        if (A -> val < B -> val)
        {
          temp-> next = A;
          A = A -> next;
        }
        else
        {
          temp -> next = B;
          B = B-> next;
        }
        temp = temp -> next;
      }
      
      if (A)
        temp -> next = A;
      
      if (B)
        temp -> next = B;
      
      return Head;
    }
};