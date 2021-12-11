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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
      ListNode* node1 = list1;
      ListNode* node2 = list2;
      
      if (node1 == NULL )
      {
        return node2;
      }
      if (node2 == NULL )
      {
        return node1;
      }
      
      ListNode* finalpointer = new ListNode();
      ListNode* finaldefinedpointer = finalpointer;
      while (node1 != NULL && node2 != NULL)
      {
        if (node1 -> val  <= node2 -> val)
        {
          finalpointer -> val = node1 -> val;
          finalpointer -> next = new ListNode();
          node1 = node1 -> next;
          finalpointer = finalpointer -> next;
        }
        else
        {
          finalpointer -> val = node2 -> val;
          finalpointer -> next = new ListNode();
          node2 = node2 -> next;
          finalpointer = finalpointer -> next;
        }
      }
      
      if (node1 == NULL && node2 != NULL)
        {
          while (node2 != NULL)
          {
            finalpointer -> val = node2 -> val;
            node2 = node2 -> next;
            if (node2 == NULL)
            {
              finalpointer-> next = NULL;
            }
            else
            {
              finalpointer -> next = new ListNode();
              finalpointer = finalpointer -> next;
            }
          }
        }
        
      if (node2 == NULL && node1 != NULL)
        {
          while (node1 != NULL)
          {
            finalpointer -> val = node1 -> val;
            node1 = node1 -> next;
            if (node1 == NULL)
            {
              finalpointer-> next = NULL;
            }
            else
            {
              finalpointer -> next = new ListNode();
              finalpointer = finalpointer -> next;
            }
          }
        }
      return finaldefinedpointer;
    }
};