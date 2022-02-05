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
  /*Merges two sorted Linked List*/
  ListNode* mergeTwoLists(ListNode* node1, ListNode* node2) {
      /* check the first two base cases 
      Not required but a good practise */
      if (node1 == NULL )
        return node2;
    
      if (node2 == NULL )
        return node1;
    
    ListNode* head = NULL;
    
    if (node1 -> val < node2 -> val)
    {
      head = node1;
      head -> next = mergeTwoLists(node1 -> next,node2);
    }
    else
    {
      head = node2;
      head -> next = mergeTwoLists(node1,node2-> next);
    }
    return head;
  }
      
  
  
    ListNode* mergeKLists(vector<ListNode*>& lists) {
      ListNode *answer;
      
      if (lists.size() == 0)
        return NULL;
      
      answer = lists[0];  
      
      for (int i = 1; i < lists.size(); i++)
        answer = mergeTwoLists(answer,lists[i]);
      return answer;
    }
};