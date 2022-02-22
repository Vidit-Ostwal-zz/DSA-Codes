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
    ListNode* oddEvenList(ListNode* head) {
      if (head == NULL)
        return head;
      
        ListNode* root = head;
      ListNode* temp = head -> next;
      ListNode* temp1 = head -> next;
      
      while (temp != NULL && root != NULL)
      {
        root->next = temp -> next;
        if (root -> next)
        {
          root = root -> next;
          temp -> next = root -> next;
        }
        temp = temp -> next;
      }
      
      root -> next = temp1;
      return head;
    }
};