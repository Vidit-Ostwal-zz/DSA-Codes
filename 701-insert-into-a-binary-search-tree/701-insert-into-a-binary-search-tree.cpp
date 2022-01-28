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
  TreeNode* pleaseinsert (TreeNode* root, int val)
  {
    if (root == NULL)
      return NULL;
    
    if (root -> val < val)
    {
      root -> right = (root->right) ? pleaseinsert(root->right,val) : new TreeNode (val);
    }
    else
    {
      root -> left = (root->left) ? pleaseinsert(root->left,val) : new TreeNode(val);
    }
    return root;
  }
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
      if (root == NULL)
      {
        root = new TreeNode(val);
        return root;
      }
        return pleaseinsert(root,val);
    }
};