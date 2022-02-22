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
  int answer = INT_MIN;
  void min_max(TreeNode* root, int mini, int maxi)
  {
    answer = max(answer,max(abs(root -> val - mini),abs(root -> val - maxi)));
    
    if (root -> left)
      min_max(root -> left, min(mini,root->val),max(maxi,root->val));
    
    if (root -> right)
      min_max(root -> right, min(mini,root->val),max(maxi,root->val));
  
  }
public:
    int maxAncestorDiff(TreeNode* root) {
       min_max(root,root->val,root ->val);
      return answer;
    }
};