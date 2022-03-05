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
  int depth(TreeNode* root, int target, int depth1)
  {
    if (root == NULL)
      return INT_MAX;
    
    if (root -> val == target)
      return depth1 + 1;
    
    return min(depth(root -> left, target, depth1+1),depth(root -> right, target, depth1+1));
  }
  
  
  TreeNode* lca(TreeNode* root, int x, int y)
  {
    if (root == NULL || root -> val == x || root -> val == y)
      return root;
    
    TreeNode* left = lca (root ->left, x,y);
    TreeNode* right = lca (root -> right,x,y);
    
    if (left != NULL && right != NULL)
      return root;
    
    return (left == NULL) ? (right) : left;
    
  }
public:
    bool isCousins(TreeNode* root, int x, int y) {
      TreeNode* temp = lca (root, x, y);
      
      int left = depth(temp, x,1);
      int right = depth(temp, y, 1);
      
      if (left != right || (left == 3 && right == 3 ))
        return false;
      
      return true;
    }
};