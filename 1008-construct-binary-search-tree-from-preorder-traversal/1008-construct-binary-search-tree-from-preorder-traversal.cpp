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
  TreeNode* recu (vector<int>&preorder,int start_index, int end_index)
  {
    if (start_index > end_index)
      return NULL;
    
    TreeNode* root = new TreeNode(preorder[start_index]);
    
    int i = start_index;
    while (i < preorder.size() && preorder[i] <= preorder[start_index])
    {
      i++;
    }
    
    root->left = recu(preorder,start_index+1,i-1);
    root->right = recu(preorder,i,end_index);
    
    return root;
    
  }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return recu(preorder,0,preorder.size()-1);
    }
};