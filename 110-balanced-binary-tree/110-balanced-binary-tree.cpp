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
public:
  
  int get_height(TreeNode* root)
  {
    if (root == NULL)
      return 0;
    
    return 1 + max(get_height(root -> left),get_height(root -> right));
  }
  
  bool  check(TreeNode* root)
  {
    if (root == NULL)
      return true;
  
    int left = get_height (root -> left);
    int right = get_height(root -> right);
    
    if (abs (left - right) <= 1 && check (root -> left) && check (root -> right))
      return true;
    
    return false;
  }
    bool isBalanced(TreeNode* root) {
        if (root == NULL)
          return true;
      
      return check(root);
    }
};