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
  long long answer = 0;
  
  vector<long long> traverse(TreeNode* root)
  {
    if (root == NULL)
      return {1,0,INT_MAX,INT_MIN};
    // Valid, Sum, Minimum Element, Maximum Element
    
    
    vector<long long> left = traverse(root -> left);
    vector<long long> right = traverse(root -> right);
    
    if (left[0] && right[0] && left[3] < root -> val && right[2] > root -> val)
    {
      long long subtree_sum = root -> val + left[1] + right[1];
      answer = max(answer,subtree_sum);
      
      int minimum = min(left[2],(long long)root -> val);
      int maximum = max(right[3],(long long)root -> val);
      
      return {1,subtree_sum,minimum,maximum};
    }
    return {0,-1,-1,-1};
  }
public:
    int maxSumBST(TreeNode* root) {
        traverse(root);
      return answer;
    }
};