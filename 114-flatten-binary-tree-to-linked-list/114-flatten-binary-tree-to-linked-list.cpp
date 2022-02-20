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
  TreeNode* prev = NULL;
  void reverse (TreeNode* root)
  {
    if (root == NULL)
      return;
    
    reverse(root -> right);
    reverse(root -> left);
    
    root -> right = prev;
    root -> left = NULL;
    prev = root;
  }
public:
    void flatten(TreeNode* root) {
        reverse(root);
    }
};