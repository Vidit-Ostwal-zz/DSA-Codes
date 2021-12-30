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
    int getDecimalValue(ListNode* head) {
        int answer = 0;
        while (head != NULL)
        {
           answer = answer *2;
          if (head -> val != 0)
          {
            answer = answer + 1;
          }
          head = head-> next;
        }
      return answer;
    }
};