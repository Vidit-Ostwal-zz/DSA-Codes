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
    vector<int> largestValues(TreeNode* root) {
      
        vector<int> answer;
      
      if (root == NULL)
        return answer;
      
      queue<TreeNode*> q;
      q.push(root);
      while (!q.empty())
      {
        int size = q.size();
        int temp_answer = INT_MIN;
        for (int i = 0 ;i < size; i++)
        {
           TreeNode* temp = q.front();
           q.pop();
          temp_answer = max(temp_answer,temp -> val);
         
          if (temp -> left != NULL) q.push(temp -> left);
          if (temp -> right != NULL) q.push(temp -> right);
        }
        answer.push_back(temp_answer);
      }
      return answer;
    }
};