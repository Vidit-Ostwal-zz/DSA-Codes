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
  int min_height (TreeNode* root)
  {
    if (root == NULL)
      return 0;
    
    if (root -> left == NULL && root -> right == NULL)
    {
      return 1;
    }
    
    int left = (root -> left != NULL) ? min_height(root -> left) : INT_MAX;
    int right = (root -> right != NULL) ? min_height(root -> right) : INT_MAX;
    return 1 + min (left,right);
  }
  
    int minDepth(TreeNode* root) { 
        return min_height(root);
    }
};