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
  bool target_sum(TreeNode* root, int target,int curr_sum)
  {
    if (root == NULL)
      return false;
    
    
    if (root -> left == NULL && root -> right == NULL)
    {
      if (target == (root -> val + curr_sum))
        return true;
      return false;
    }
    
    bool left = target_sum(root->left,target,curr_sum + root->val);
    bool right = target_sum(root->right,target,curr_sum + root-> val);
    
    if (left || right)
      return true;
    
    return false;
  }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        return target_sum(root,targetSum,0);
    }
};