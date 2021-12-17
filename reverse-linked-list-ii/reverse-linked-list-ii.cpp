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
  
  /*index takes direct position*/
  ListNode* get (ListNode* head, int index)
  {
    index--;
    while (index != 0)
    {
      head = head-> next;
      index--;
    }
    return head;
  }
  
  
  /*work of reversing the linked list*/
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
  
  
  ListNode* reversepart (ListNode* head, int left1, int right1)
  {
    /* starting from head and in between */
    if (left1 == 1 && get(head,right1)-> next != NULL)
    {
      ListNode* left = get(head,left1);
      ListNode* right = get(head,right1);
      ListNode* future  = get(head,right1+1);
      right-> next = NULL;
      
      ListNode* Head = reverselinkedlist(left);
      ListNode* temp = Head;
      while(temp -> next != NULL)
      {
        temp = temp-> next;
      }
      temp -> next = future;
      return Head;
    }
    
    /* Starting not from head and ending at the end */
    if (left1 != 1 && get(head,right1)-> next == NULL)
    {
      ListNode* prev = get(head, left1-1);
      ListNode* left = get(head,left1);
      prev -> next = reverselinkedlist(left);
      return head;
    }
    
    /*In between cases */
    ListNode* prev = get(head, left1-1);
    ListNode* left = get(head,left1);
    ListNode* right = get(head,right1);
    ListNode* future  = get(head,right1+1);
    right-> next = NULL;
    
    prev -> next = reverselinkedlist(left);
    while(prev -> next != NULL)
    {
      prev = prev-> next;
    }
    prev-> next = future;
    return head;
  }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
      
       if (head == NULL || head -> next == NULL || left == right)
      {
        return head;
      }
      if (left == 1 && get(head,right) -> next == NULL)
      {
        return reverselinkedlist(head);
      }
        return reversepart (head,left,right);
    }
};