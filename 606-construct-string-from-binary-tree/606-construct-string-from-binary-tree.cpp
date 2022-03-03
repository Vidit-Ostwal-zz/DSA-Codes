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
  string preorder_traversal(TreeNode* root)
  {
    if (root == NULL)
      return "";
    
    if (root -> left == NULL && root -> right == NULL)
      return to_string(root -> val);
    
    string temp = to_string(root->val);
    temp += "(";
    temp += preorder_traversal(root ->left);
    temp += ")";
    
    if (root -> right != NULL)
    {
      temp += "(";
      temp += preorder_traversal(root ->right);
      temp += ")";
    }
    
    return temp;
  }
public:
    string tree2str(TreeNode* root) {
        return preorder_traversal(root);
    }
};