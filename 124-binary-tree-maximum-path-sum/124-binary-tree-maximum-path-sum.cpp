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
  int answer = INT_MIN;
  
  int findmax(TreeNode* root)
  {
    if (root == NULL)
      return 0;
    
    int left = findmax(root -> left);
    int right = findmax(root -> right);
    answer = max(max(root -> val,answer),max(root-> val +left+right, root-> val + max(left,right)));
    return max(root -> val, root -> val + max(left,right));
  }
  
  
    int maxPathSum(TreeNode* root) {
      findmax(root);
      return answer;
      
    }
};