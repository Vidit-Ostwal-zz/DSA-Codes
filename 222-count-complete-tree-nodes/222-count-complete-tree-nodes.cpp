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
  int preorder(TreeNode* root)
  {
    if (root -> left == NULL && root -> right  == NULL)
      return 1;
    int left = (root -> left != NULL) ? preorder(root -> left) : 0;
    int right = (root -> right != NULL) ? preorder(root -> right) : 0;
    
    return 1 + left+right;
  }
public:
    int countNodes(TreeNode* root) {
      if (root == NULL)
        return 0;
        return preorder(root);
    }
};