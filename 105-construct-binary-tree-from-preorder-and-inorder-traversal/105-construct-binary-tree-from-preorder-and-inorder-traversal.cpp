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
  public:
  unordered_map<int,int> mp;
  int i = 0;
  TreeNode* make_tree(vector<int> preorder,vector<int> inorder, int s,int e)
  {
    if (s>e)
      return NULL;
    
    TreeNode* root = new TreeNode(preorder[i++]);
    int root_index = mp[root->val];
    
    root->left = make_tree(preorder,inorder,s,root_index-1);
    root-> right = make_tree(preorder,inorder,root_index+1,e);
    
    return root;
  }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
      /*Stores the indexes making searching indexes faster*/
      
      for (int i=  0; i < inorder.size();i++)
      {
        mp[inorder[i]] = i;
      }
      
      TreeNode* root = make_tree(preorder,inorder,0,inorder.size()-1);
      
      return root;
    }
};