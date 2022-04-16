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
  int maxi = 0;
  void reversepreorder(TreeNode *root)
  {
    if (root == NULL)
      return ;
    
    // if (root -> right)
    reversepreorder(root -> right);
    root -> val += maxi;
    maxi = root -> val;
    // if (root -> left)
    reversepreorder(root -> left);
  }
public:
    TreeNode* bstToGst(TreeNode* root) {
        reversepreorder(root);
      return root;
    }
};