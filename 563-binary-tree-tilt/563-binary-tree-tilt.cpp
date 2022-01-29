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
  int answer = 0;
  int tilt(TreeNode* root)
  {
    if (root == NULL)
      return 0;
    
    if (root -> left == NULL && root -> right == NULL)
    {
      return root->val;
    }
    
    int left = tilt(root -> left);
    int right = tilt(root -> right);
    
    answer += abs(left - right);
    
    return left+right+root->val;
  }
public:
    int findTilt(TreeNode* root) {
      tilt(root);
        return answer;
    }
};