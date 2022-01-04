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
  /*Reverse an entire lenked list*/
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
  
  ListNode* reversesplitmiddle (ListNode *head)
  {
    ListNode* slow = head;
    ListNode* fast = head;
    ListNode* prev = NULL;
    do
    {
      prev = slow;
      slow = slow -> next;
      fast = fast -> next -> next;
    } while (fast!= NULL && fast -> next != NULL);
      
    prev-> next = NULL;
    slow = reverselinkedlist(slow);
    return slow;
  }
      
  ListNode* merge (ListNode *head, ListNode* slow)
  {
    ListNode *Head = head;
    ListNode * temp = NULL;
    while(head != NULL && slow != NULL)
    {
      temp = head -> next;
      head -> next = slow;
      
      head = temp;
      
      temp = slow -> next;
      if ((head == NULL && temp == NULL) || head != NULL)
      {
        slow -> next = head;
      }
      else
      {
        return Head;
      }
      slow = temp;
    }
    
    return Head;
  }
      
    void reorderList(ListNode* head) {
      
      if (head == NULL || head -> next == NULL)
      {
        return ;
      }
      
      ListNode* middle = reversesplitmiddle (head);
      head = merge(head,middle);
    }
};