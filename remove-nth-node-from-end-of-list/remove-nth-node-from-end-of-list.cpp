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
  /*return the length of the list*/
  int linkedlength(ListNode* head)
  {
    int count = 0;
    while (head != NULL)
    {
      count++;
      head = head -> next;
    }
    return count;
  }
  
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
  
  
  
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == NULL || head -> next == NULL)
      {
        if (head == NULL)
        {
          return head;
        }
        else
        {
          head = NULL;
        }
          return head;
      }
      
      int length = linkedlength(head);
      int index = length+1-n;
      
      if (index == 1)
      {
        return head-> next;
      }
      ListNode* prev = get(head,index-1);
      ListNode* future = get(head,index);
      
      prev -> next = future -> next;
      
      return head;
    }
};