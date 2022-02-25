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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
  vector<TreeNode*> find_val (int val, TreeNode* root)
  {
    vector<TreeNode*> temp1;
    if (root == NULL)
      return {};
    
    if (root -> val == val)
      temp1.push_back(root);
    
    vector<TreeNode*> left = find_val(val, root -> left);
    vector<TreeNode*> right = find_val(val, root -> right);
    
    left.insert(left.end(),right.begin(),right.end());
    temp1.insert(temp1.end(),left.begin(),left.end());
    return temp1;
  }
  
  bool get_check(ListNode* head, TreeNode* root)
  {
    if (head == NULL)
      return true;
    
    if (root == NULL)
      return false;
    
    if (head -> val == root -> val)
      return get_check(head -> next, root -> left) || get_check(head -> next, root -> right);
    
    return false;
  }
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        vector<TreeNode*> temp  = find_val(head -> val,root);
      cout << temp.size() << endl;
      for (int i = 0 ;i < temp.size(); i++)
      {
        if (get_check(head,temp[i]))
          return true;
      }
      return false;
    }
};