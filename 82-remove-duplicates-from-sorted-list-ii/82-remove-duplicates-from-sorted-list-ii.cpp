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
  ListNode* deletedupli(ListNode* head)
  {
    if (head == NULL)
      return head;
    
    int count = 0;
    while (head -> next != NULL && head != NULL && head -> val == head -> next -> val)
    {
      count++;
      head = head -> next;
    }
    if (count)
      return deletedupli(head -> next);
    
    ListNode* temp = new ListNode(head -> val);
    temp -> next = deletedupli(head -> next);
    return temp;
  }
public:
    ListNode* deleteDuplicates(ListNode* head) {
        return deletedupli(head);
    }
};