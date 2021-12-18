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
  
    ListNode* rotateRight(ListNode* head, int k) {
       if (head == NULL || head -> next == NULL || left == right)
      {
        return head;
      }
      
      int length = linkedlength(head);
      
      k  = k% length;
      
      if (k == 0)
      {
        return head;
      }
      ListNode* prevHead = get(head, length -k);
      ListNode* Head = get (head, length -k +1);
      ListNode* Last = get (head, length);
      
      Last -> next = head;
      prevHead -> next = NULL;
      return Head;
    }
};