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
  TreeNode* removetarget (TreeNode* child, TreeNode* root, int target, bool left)
  {
    if (child == NULL)
      return NULL;
    
    child -> left = removetarget(child -> left, child, target, true);
    child -> right = removetarget(child -> right,child, target,false);
    
    if (child -> left == NULL && child -> right == NULL && child -> val == target)
    {
      if (left)
        root -> left = NULL;
      else
        root -> right = NULL;  
    }
    return (left) ? root -> left : root -> right;
  }
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
      root -> left = removetarget(root -> left, root, target, true);
      root -> right = removetarget(root -> right, root, target, false);
      
      if (root -> left == NULL && root -> right == NULL && root -> val == target)
        return NULL;
      
      return root;
    }
};