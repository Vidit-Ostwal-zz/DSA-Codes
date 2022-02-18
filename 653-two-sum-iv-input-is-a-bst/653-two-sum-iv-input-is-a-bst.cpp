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
  void get_inorder(TreeNode* root)
  {
    if (root == NULL)
      return;
    
    get_inorder(root ->left);
    inorder.push_back(root -> val);
    get_inorder(root -> right);
    
  }
public:
    bool findTarget(TreeNode* root, int k) {
      get_inorder(root);
      
      int start = 0;
      int end = inorder.size()-1;
      
      while (start < end)
      {
        int sum = inorder[start] + inorder[end];
        if (sum == k)
          return true;
        
        if (sum > k)
          end--;
        
        else
          start++;
      }
      return false;
    }
};