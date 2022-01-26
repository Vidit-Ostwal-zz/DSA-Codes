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
  
  TreeNode* make_tree(vector<int> preorder,int pre_start,int pre_end,vector<int> inorder, int in_start, int in_end)
  {
    if (pre_start > pre_end || in_start > in_end)
      return NULL;
    
    TreeNode* root = new TreeNode(preorder[pre_start]);
    int root_index = mp[preorder[pre_start]];
    int length = root_index - in_start;
    
    root->left = make_tree(preorder,pre_start+1,pre_start+length,inorder,in_start,in_end-1);
    root-> right = make_tree(preorder,pre_start+length+1,pre_end,inorder,root_index+1,in_end);
    
    return root;
  }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
      /*Stores the indexes making searching indexes faster*/
      
      for (int i=  0; i < inorder.size();i++)
      {
        mp[inorder[i]] = i;
      }
      
      TreeNode* root = make_tree(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1);
      
      return root;
    }
};