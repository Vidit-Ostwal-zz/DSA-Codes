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
  int maxi=  0;
  int get_length(TreeNode* root, bool flag)
  {
    if (root == NULL)
      return 0;
    
    if (flag)
    {
      int temp = get_length(root -> left,true);
      maxi  = max(maxi,temp);
      return 1+ get_length(root -> right,false);
    }
      
    int temp = get_length(root -> right,false);
    maxi  = max(maxi,temp);
    return 1 + get_length(root -> left,true);
  }
public:
    int longestZigZag(TreeNode* root) {
        int l = get_length(root->left,true);
      int r = get_length(root -> right,false);
      maxi = max(maxi,max(l,r));
      return maxi;
    }
};