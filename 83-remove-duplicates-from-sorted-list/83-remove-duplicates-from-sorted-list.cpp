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
    ListNode* deleteDuplicates(ListNode* head) {
      
      if (head == NULL || head -> next == NULL)
        return head;
      
        // Recursive Approach
      ListNode* temp = head;
      
      // Loop till the last element
      while (temp -> next != NULL)
      {
        if (temp -> val == temp -> next -> val)
          temp -> next = temp -> next -> next;
        else
          temp = temp -> next;
      }
      return head;
    }
};