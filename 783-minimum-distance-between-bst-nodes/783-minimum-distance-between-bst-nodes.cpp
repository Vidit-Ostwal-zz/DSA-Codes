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
    int minDiffInBST(TreeNode* root) {
        get_inorder(root);
      int answer = INT_MAX;
      for (int i = 1; i < inorder.size(); i++)
        answer = min(answer,inorder[i]-inorder[i-1]);
      
      return answer;
    }
};