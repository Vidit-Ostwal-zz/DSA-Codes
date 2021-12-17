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
  
  /*Reversing Linked List 
  Time Complexity = O(N) 
  Space Complexity  = O(1)
  */
  ListNode* reverselinkedlist (ListNode* Head)
  {
    ListNode* prev = NULL;
    ListNode* present = Head;
    ListNode* future = present-> next;
    
    do 
    {
      present -> next = prev;
      prev = present;
      present = future;
      if (future != NULL)
      {
        future = future -> next;
      }
    }while(present != NULL);
    
    return prev;
  }
  
  /*Reversing half of the linked list and then comparing with the previous half to maintain constant space*/
    bool isPalindrome(ListNode* head) {
      if (head == NULL || head -> next == NULL)
      {
        return head;
      }
      
      ListNode* slow = head;
      ListNode* fast = head;
      ListNode* prev = NULL;
      do
      {
        prev = slow;
        slow = slow -> next;
        fast = fast -> next -> next;
      }while (fast!= NULL && fast -> next != NULL);
      
      /*slow will be the middle element */
      prev-> next = NULL;
      slow = reverselinkedlist(slow);
      
      while (head != NULL)
      {
        if (head -> val != slow -> val)
        {
          return false;
        }
        head = head -> next;
        slow = slow -> next;
      }
      return true;
    }
};