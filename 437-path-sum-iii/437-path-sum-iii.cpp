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
  
  vector<long long> Recursive_Count(TreeNode* root, int target)
  {
    if (root == NULL)
    {
      return {};
    }
    
    vector<long long> left = Recursive_Count(root->left,target);
    vector<long long> right = Recursive_Count(root->right,target);
    
    vector<long long> combined;
    
    if (root ->val == target)
      answer++;
    
    combined.push_back(root->val);
    
    for (int i = 0; i < left.size(); i++)
    {
      if (left[i] + root ->val == target)
        answer++;
      combined.push_back(left[i] + root ->val);

    }
    
    for (int j = 0; j < right.size(); j++)
    {
      if (right[j] + root ->val == target)
        answer++;
      combined.push_back(right[j] + root ->val);
    }
    return combined;
  }
public:
    int pathSum(TreeNode* root, int targetSum) {
      
      Recursive_Count(root, targetSum);
      return answer;
    }
};