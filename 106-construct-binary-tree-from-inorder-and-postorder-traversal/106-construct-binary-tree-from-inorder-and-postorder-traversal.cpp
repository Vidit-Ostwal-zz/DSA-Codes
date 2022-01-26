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
  
  TreeNode* make_tree(vector<int> postorder,int ps, int pe,vector<int> inorder, int is,int ie)
  {
    if (ps > pe || is > ie)
      return NULL;
    
    TreeNode* root = new TreeNode(postorder[pe]);
    int root_index = mp[root->val];
    int length = ie - root_index;
    
     root -> left = make_tree(postorder,ps,pe-length-1,inorder,is,root_index-1);
    root -> right = make_tree(postorder,pe-length,pe-1,inorder,root_index+1,ie);
    
    /*
    root->left = make_tree(preorder,ps+1,ps+length,inorder,is,root_index-1);
    root-> right = make_tree(preorder,ps+length+1,pe,inorder,root_index+1,ie);
    */
    return root;
  }
  
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        /*Stores the indexes making searching indexes faster*/
      for (int i=  0; i < inorder.size();i++)
      {
        mp[inorder[i]] = i;
      }
      TreeNode* root = make_tree(postorder,0,inorder.size()-1,inorder,0,inorder.size()-1);
      return root;
    }
};