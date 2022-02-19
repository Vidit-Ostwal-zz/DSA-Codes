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
  ListNode* reverse(ListNode* root)
 {
  ListNode* pre = NULL;
  ListNode* curr = root;
  ListNode* fut = root -> next;
    while (curr != NULL)
    {
   curr -> next = pre;
   pre = curr;
   curr = fut;
   fut = (fut != NULL) ? fut -> next : NULL;
  }
  return pre;
  }
  
  int siz1 (ListNode* root)
  {
    int lg = 0;
    while (root != NULL)
    {
      lg++;
      root = root -> next;
    }
    return lg;
  }
public:
    int pairSum(ListNode* head) {
        int size = siz1(head);
      
      ListNode* temp = head;
      int i = 1;
      while (i < size/2)
      {
        temp = temp -> next;
        i++;
      }
      
      ListNode* nexthalf = temp -> next;
      temp -> next = NULL;
      nexthalf = reverse(nexthalf);
      
      int answer = INT_MIN;
      while (nexthalf != NULL && head != NULL)
      {
        answer = max(answer, nexthalf -> val + head -> val);
        nexthalf = nexthalf -> next;
        head = head -> next;
      }
      return answer;
    }
};