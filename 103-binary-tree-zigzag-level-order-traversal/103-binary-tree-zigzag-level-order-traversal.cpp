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
    
    queue<TreeNode*> q;
    q.push(root);
    bool flag = true;
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
      if (!flag)
        reverse(temp_vector.begin(),temp_vector.end());
      
      flag = !flag;
      final_vector.push_back(temp_vector);
    }
    return final_vector;
  }
  
  
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
      if (root == NULL)
      {
        vector<vector<int>> final_vector;
        return final_vector;
      }
      return optimized_level_order(root);
    }
};