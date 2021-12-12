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
For finding middle of the linked list with jsut one pass,
again two pointer approach
*/
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
      ListNode* slow = head;
      ListNode* fast = head;
      
      while (fast-> next != NULL)
      {
        if (fast -> next -> next != NULL)
        {
          fast = fast -> next -> next;
        }
        else
        {
          fast = fast -> next;
        }
        slow = slow -> next;
      }
      return slow;
    }
};