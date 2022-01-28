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
  int answer = -1;
  int count = 0;
  
  void inorder_traversal(TreeNode* root, int k)
  {
    if (root == NULL)
      return ;
    
    inorder_traversal(root->left,k);
    count++;
    if (count == k)
      answer = root->val;
    
    inorder_traversal(root->right,k);  
  }
public:
    int kthSmallest(TreeNode* root, int k) {
      inorder_traversal(root,k);  
      return answer;
    }
};