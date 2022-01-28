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
  TreeNode* search(TreeNode* root,int val)
  {
    if (root == NULL)
      return NULL;
    
    if (root->val == val)
      return root;
    
    return (root -> val >val ) ? search(root->left,val) : search(root->right,val);
  }
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        return search(root,val);
    }
};