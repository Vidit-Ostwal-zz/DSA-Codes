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
  vector<int> inorder;
 int inorder_traversal(TreeNode* root,int sum)
 {
  if (root == NULL)
   return 0 ;
   
   if (root -> left == NULL && root -> right == NULL)
     return sum * 10  + root -> val;
   
   sum  = sum *10 + root -> val;
   
  return inorder_traversal(root -> left,sum) + inorder_traversal(root -> right,sum);
 }
public:
    int sumNumbers(TreeNode* root) {
        return inorder_traversal(root,0);
    }
};