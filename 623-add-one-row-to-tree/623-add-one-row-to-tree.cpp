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
    TreeNode* addOneRow(TreeNode* root, int val, int dth) {
        queue<TreeNode*> q;
      q.push(root);
      int depth = 1;
      if (depth == dth)
      {
        TreeNode* answer = new TreeNode(val);
        answer -> left = root;
        return answer;
      }
      while (!q.empty())
      {
        int size = q.size();
        depth++;
        cout << size << depth <<  endl;
       
        
        if (depth != dth)
        {
          for (int i = 0; i < size; i++)
          {
          TreeNode* temp = q.front();
          q.pop();
          
          if (temp -> left != NULL) q.push(temp -> left);
          if (temp -> right != NULL )q.push(temp -> right);
          }
        }
        else
        {
          while (!q.empty())
          {
            TreeNode* temp = q.front();
            q.pop();
              TreeNode* temp1 = temp -> left;
              temp -> left = new TreeNode(val);
              temp -> left -> left = temp1;             
              TreeNode* temp2 = temp -> right;
              temp -> right = new TreeNode(val);
              temp -> right -> right = temp2;
          }
        }
      }
      return root;
    }
};