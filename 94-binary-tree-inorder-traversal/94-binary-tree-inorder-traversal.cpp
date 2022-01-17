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
  void recursive_solution(TreeNode* root, vector<int>& final_vector)
  {
    if (root == NULL)
      return;
    
    recursive_solution(root-> left,final_vector);
    final_vector.push_back(root -> val);
    recursive_solution(root-> right,final_vector);
  }
  
  
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> final_vector;
      recursive_solution(root,final_vector);
      return final_vector;
    }
};