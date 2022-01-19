/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
   TreeNode* lca (TreeNode* root,TreeNode* p, TreeNode* q)
  {
    if((root == NULL) ||  (root == p) || (root == q))
      return root;
   
    TreeNode* left = lca (root -> left,p,q);
    TreeNode* right = lca (root -> right,p,q);
    
    if (left != NULL  && right != NULL)
    {
      return root;
    }
    else
      return (left == NULL)? right : left;
  }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return lca (root,p,q);
    }
};