/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/*
Using two pointer approach
Space Complexity = O(N)
Time Complexity = O(N)

They will gurantely meet once slow pointer enters the cycle (if present)
*/
class Solution {
public:
    bool hasCycle(ListNode *head) {
      ListNode* Slow = head;
      ListNode* Fast = head;
      
      while (Fast != NULL && Fast -> next != NULL)
      {
        Fast = Fast->next -> next;
        Slow = Slow-> next;
        
        if (Fast == Slow)
        {
          return true;
        }
      }
      return false;
    }
};