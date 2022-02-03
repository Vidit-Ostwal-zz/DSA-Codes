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
  TreeNode* convert(vector<int> nums, int start_index, int end_index)
  {
    if (start_index > end_index)
      return NULL;
    
    int mid_index = (start_index + end_index)/2;
    
    TreeNode *root = new TreeNode(nums[mid_index]);
    
    root -> left = convert(nums,start_index,mid_index-1);
    root -> right = convert(nums,mid_index+1,end_index);
    
    return root;
  }
  
  
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return convert(nums,0,nums.size()-1);
    }
};