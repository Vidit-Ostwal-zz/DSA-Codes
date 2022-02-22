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
  int size = 0;
  ListNode* reverse(ListNode* root)
 {
  ListNode* pre = NULL;
  ListNode* curr = root;
  ListNode* fut = root -> next;
   
  while (curr != NULL)
  {size++;
   curr -> next = pre;
   pre = curr;
   curr = fut;
   fut = (fut != NULL) ? fut -> next : NULL;
  }
  return pre;
  }
public:
    vector<int> nextLargerNodes(ListNode* head) {
        head = reverse(head);
      vector<int> answer(size);
      
      stack<int> st;
      while (head != NULL)
      {
        int curr = head -> val;
        while (!st.empty() && curr >= st.top())
          st.pop();
        
        if (st.empty())
          answer[size-1] = 0;
        else
          answer[size-1] = (st.top());
        
        st.push(head -> val);
        head = head -> next;
        size--;
      }
      return answer;
    }
};