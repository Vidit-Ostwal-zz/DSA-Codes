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
  vector<vector<int>> optimized_level_order(TreeNode* root)
  {
    vector<vector<int>> final_vector;
    if (root == NULL)
      return final_vector;
    queue<TreeNode*> q;
    q.push(root);
   
    while(!q.empty())
    {
      int size = q.size();
      vector<int> temp_vector;
      for (int i = 0; i < size; i++)
      {
        root = q.front();
        q.pop();
        temp_vector.push_back(root -> val);
        if (root -> left != NULL)
          q.push(root -> left);
        
        if (root -> right != NULL)
          q.push(root -> right);
      }
      final_vector.push_back(temp_vector);
    }
    reverse(final_vector.begin(),final_vector.end());
    return final_vector;
  }
  
  
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        return optimized_level_order(root);
    }
};