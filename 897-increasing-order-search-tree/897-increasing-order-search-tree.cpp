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
  /*similar to transforming to linked list*/
  TreeNode* temp = NULL;
  void make_linear(TreeNode* root)
  {
    if (root == NULL)
      return ;
    
    make_linear(root -> right);
    root -> right = temp;
    temp = root;
    make_linear(root -> left);
    root -> left = NULL;
    
  }
public:
    TreeNode* increasingBST(TreeNode* root) {
        make_linear(root);
      return temp;
    }
};