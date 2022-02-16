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
  vector<vector<int>> target_sum(TreeNode* root, int target,int curr_sum,vector<int> temp)
  {
    vector<vector<int>> temp_vector;
    if (root == NULL)
      return temp_vector;
    
    
    temp.push_back(root -> val);
    if (root -> left == NULL && root -> right == NULL)
    {
      if (target == (root -> val + curr_sum))
      {
        temp_vector.push_back(temp);
        return temp_vector;
      }
      return temp_vector;
    }
    
    vector<vector<int>> left = target_sum(root->left,target,curr_sum + root->val,temp);
    vector<vector<int>> right = target_sum(root->right,target,curr_sum + root-> val,temp);
    
    left.insert(left.end(),right.begin(),right.end());
    return left;
  }
public:
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        return target_sum(root,target,0,{});
    }
};