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
    ListNode* removeElements(ListNode* head, int val) {
     
      ListNode *presentnode = head;
      ListNode *previousnode = presentnode;

      while (presentnode != NULL)
      {
        if (presentnode -> val == val)
        {
          if (presentnode == head)
          {
            cout << " Yes" << endl;
            head = head -> next;
            presentnode = head;
            previousnode = head;
          }
          else
          {
          previousnode -> next = presentnode -> next;
          presentnode = presentnode-> next;
          }
        }
        else
        {
          previousnode = presentnode;
          presentnode = presentnode-> next;
        }
      }
      return head;
    }
};