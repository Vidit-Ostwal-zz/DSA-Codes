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
  
    ListNode* swapNodes(ListNode* head, int k) {
      int length = linkedlength(head);
      ListNode* left = get(head,k);
      ListNode* right = get(head,length - k +1);
      
      int temp = right -> val;
      right -> val = left -> val;
      left -> val = temp;
      return head;
    }
};