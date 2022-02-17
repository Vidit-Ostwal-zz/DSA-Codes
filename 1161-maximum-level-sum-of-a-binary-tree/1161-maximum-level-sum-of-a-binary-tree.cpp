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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
      q.push(root);
      
      int maximal = INT_MIN;
      int answer = 0;
      
      int level = 0;
      while (!q.empty())
      {
        level++;
        int size = q.size();
        int temp  = 0;
        
        for (int i= 0; i < size; i++)
        {
          TreeNode* tmp = q.front();
          q.pop();
          
          temp += tmp ->val;
          if (tmp -> left) q.push(tmp->left);
          if (tmp -> right) q.push(tmp -> right);
        }
        if (temp > maximal)
        {
          maximal = temp;
          answer = level;
        }
      }
      return answer;
    }
};