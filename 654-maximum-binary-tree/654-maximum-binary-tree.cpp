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
  int get_max_index (vector<int> nums, int start_index, int end_index)
  {
    int maxi = INT_MIN;
    int maxi_index = -1;
    for (int i = start_index; i <= end_index;i++)
    {
      if (maxi < nums[i])
      {
        maxi = nums[i];
        maxi_index = i;
      }
    }
    
    return maxi_index;
  }
  
  TreeNode* createTree(vector<int>nums,int start_index, int end_index)
  {
    if (start_index >  end_index)
      return NULL;
    
    int maxi_index = get_max_index(nums,start_index,end_index);
    TreeNode* root = (maxi_index == -1) ? NULL  : new TreeNode(nums[maxi_index]);
    if (root == NULL) return root;
    
    root -> left = createTree(nums,start_index,maxi_index-1);
    root -> right = createTree(nums,maxi_index+1,end_index);
    
    return root;
  }
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return createTree(nums,0,nums.size()-1);
    }
};