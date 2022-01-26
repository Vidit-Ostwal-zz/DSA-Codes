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
  
  int via_property(TreeNode* root)
  {
    if (root == NULL)
      return 0;
    
    int left = 0;
    int right = 0 ;
    
    TreeNode* Lf = root;
    while (Lf != NULL)
    {
      left++;
      Lf = Lf -> left;
    }
    TreeNode* Rf = root;
    while(Rf != NULL)
    {
      right++;
      Rf = Rf -> right;
    }
    
    if (left == right)
    {
      return pow(2,left) - 1;
    }
    return 1 + via_property(root-> left)+ via_property(root->right);
    
  }
public:
    int countNodes(TreeNode* root) {
      if (root == NULL)
        return 0;
        return via_property(root);
    }
};