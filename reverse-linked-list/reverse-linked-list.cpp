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
   /*Approach One*/
  /*
  Time Complexity = O(N)
  Space Complexity = O(N)
 
  ListNode* insertfirst(int value, ListNode* head)
  {
    ListNode* New = new ListNode();
    New -> val = value;
    New -> next = head;
    head = New;
    return head;
  }
  
  
    ListNode* reverseList(ListNode* head) {
      ListNode* reversehead = NULL;  
      while(head != NULL)
        {
        reversehead = insertfirst(head->val, reversehead);
        head = head->next;
        }
      return reversehead;
    }
};
*/
  
  /*Approach Two Recursive Approach*/
  /*
  Time Complexity = O(N)
  Space Complexity= O(1)
  
  ListNode* Head = NULL;
  ListNode* Tail = NULL;
  
  void reverselinkedlist(ListNode* head)
  {
    if (head == Tail)
    {
      Head = head;
    }
    else
    {
      reverselinkedlist(head->next);
      Tail -> next = head;
      Tail = head;
      Tail -> next = NULL;
    }
  }
  
    ListNode* reverseList(ListNode* head) {
      if ( head == NULL || head -> next == NULL)
        return head;
      ListNode* temp = head;
      Head = head;
      while (temp -> next != NULL)
      {
        temp = temp->next;
      }
      Tail = temp;
      reverselinkedlist(head);
      return Head;
    }
  
};

*/
  
  /*Approach Three Iterative Approach*/
  /*One does get a Tail, 3 pointer approach
  Time Complexity = O(N)
  Space Complexity = O(1)
  */
  
    ListNode* reverseList(ListNode* head) {
      if ( head == NULL || head -> next == NULL)
      {
        return head;
      }
      
      ListNode *prev = NULL;
      ListNode *present = head;
      ListNode *future = head->next;
      
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
};