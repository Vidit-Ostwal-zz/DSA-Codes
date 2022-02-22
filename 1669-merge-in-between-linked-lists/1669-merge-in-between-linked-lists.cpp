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
  pair<ListNode*,ListNode*> traverse (ListNode* root, int a)
  {
    ListNode* temp;
    while(a > 0)
    {
      temp = root ;
      root = root -> next;
      a--;
    }
    return make_pair(temp,root);
  }
  
  ListNode* traverse1 (ListNode* root)
  {
    while (root -> next != NULL)
      root = root -> next;
    
    return root;
  }
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        auto it = traverse(list1,a);
      auto it1 = traverse(list1,b);
      
      it.first -> next = list2;
      list2 = traverse1(list2);
      list2 -> next = it1.second -> next;
      return list1;
    }
};