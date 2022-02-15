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
    
    return 1 + max(get_height(root ->left),get_height(root -> right));
  }
  
  
  TreeNode* getTreeNode(TreeNode* root)
  {
    int left = get_height(root -> left);
    int right = get_height(root -> right);
    
    if (left == right)
      return root;
    
    if (left > right)
      return getTreeNode(root -> left);
    
    return getTreeNode(root -> right);
  }
  
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return getTreeNode(root);
    }
};