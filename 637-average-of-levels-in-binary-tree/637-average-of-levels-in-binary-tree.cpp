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
    vector<double> averageOfLevels(TreeNode* root) {
        queue <TreeNode*> q;
      q.push(root);
      
      vector<double> answer;
      
      while (!q.empty())
      {
        int size = q.size();
        double temp1 = 0;
        for (int i = 0; i < size; i++)
        {
          TreeNode* temp = q.front();
          q.pop();
          temp1 += temp -> val;
          if (temp -> left != NULL) q.push(temp -> left);
          if (temp -> right != NULL) q.push(temp -> right);
        }
        answer.push_back(temp1/size);
      }
      return answer;
    }
};