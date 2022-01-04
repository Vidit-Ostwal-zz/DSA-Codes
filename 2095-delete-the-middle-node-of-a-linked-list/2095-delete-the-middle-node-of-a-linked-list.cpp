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
  
  ListNode* deletemiddlenode (ListNode* head)
  {
    ListNode *fast = head;
    ListNode *slow = head;
    ListNode *prev_slow = slow;
    
    do 
    {
      prev_slow = slow;
      fast = fast -> next -> next;
      slow = slow -> next;
    }while(fast != NULL && fast -> next != NULL);
    
    prev_slow -> next = slow -> next;
    return head;
  }
    ListNode* deleteMiddle(ListNode* head) {
      if (head == NULL || head -> next == NULL)
      {
        head = NULL;
        return head;
      }
        return deletemiddlenode(head);
    }
};