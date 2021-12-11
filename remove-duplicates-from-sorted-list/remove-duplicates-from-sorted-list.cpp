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
/*
Function return a List node pointer
First important check 
whether given input is NULL or not
while loop to iterate over the linked list till the last and 
if else condition for changing


Time Complexity : O(N)
Space Complexity : O(1)
*/
class Solution {
public:
  
    ListNode* deleteDuplicates(ListNode* head) {
      ListNode* node = head;
      if (node == NULL)
      {
        return node;
      }
      while (node->next != NULL)
      {
        if (node->next->val == node->val)
        {
          node->next = node->next->next;
        }
        else
        {
          node = node->next;
        }
      }
      return head;
    }
};