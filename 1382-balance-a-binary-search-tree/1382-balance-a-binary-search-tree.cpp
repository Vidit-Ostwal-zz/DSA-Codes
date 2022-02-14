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
  void inorder_traversal(TreeNode* root)
  {
    if (root == NULL)
      return;
    
    inorder_traversal(root -> left);
    inorder.push_back(root -> val);
    inorder_traversal(root -> right);
  }
  
  TreeNode* make_binary(vector<int> inorder, int st_index, int ed_index)
  {
    if (st_index > ed_index)
      return NULL;
    
    int mid = (ed_index + st_index) / 2;
    
    TreeNode* root = new TreeNode(inorder[mid]);
    
    root -> left = make_binary(inorder,st_index,mid-1);
    root -> right = make_binary(inorder,mid+1,ed_index);
    
    return root;
  }
public:
    TreeNode* balanceBST(TreeNode* root) {
        inorder_traversal(root);
      
      return make_binary(inorder,0,inorder.size()-1);
    }
};