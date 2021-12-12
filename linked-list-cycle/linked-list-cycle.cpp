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

Bluid over this find the length of cycle
After knowing that there is a cycle, instead of returning true, iterate or use do-while loop and increase slow by one 
and keep fast there only, and keep increasing the count, once they agian meet, return the count.

If cycle is not there return 0
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
