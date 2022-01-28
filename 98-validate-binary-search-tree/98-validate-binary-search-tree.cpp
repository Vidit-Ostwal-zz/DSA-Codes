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
  bool checkBST(TreeNode* root, long long int lower_index, long long int higher_index)
  {
    if (root == NULL)
      return true;
    
    if (root -> val > lower_index && root-> val < higher_index && checkBST(root->left,lower_index,root->val) && checkBST(root->right,root->val,higher_index))
      return true;
    
    return false;
  }
public:
    bool isValidBST(TreeNode* root) {
      if (root != NULL && root->left == NULL && root-> right == NULL)
        return true;
      
        return checkBST(root,LONG_MIN,LONG_MAX); 
    }
};