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
  bool Helper(TreeNode* root)
  {
    if (root == NULL)
      return true;
    
    queue<TreeNode*> q;
    q.push(root);
    
    int index = 0;
    while (!q.empty())
    {
      int size = q.size();
      
      int temp1 = INT_MIN;
      int temp2 = INT_MAX;
      int flag = 0;
      for (int i = 0; i < size; i++)
      {
        TreeNode* fi = q.front();
        // cout << fi -> val << endl;
        
        q.pop();
        if (index%2 == 0)
        {
          if (fi -> val % 2 == 0)
            return false;
          
          if (temp1 < fi->val)
          {
            flag++;
            temp1 = fi -> val;
          }
          
          if (fi -> left != NULL)
            q.push(fi -> left);
          
          if (fi -> right != NULL)
            q.push(fi -> right);
        }
        else
        {
          if (fi -> val % 2)
            return false;
          
          if (temp2 > fi -> val)
          {
            flag++;
            temp2 = fi -> val;
          }
          
          if (fi -> left != NULL)
            q.push(fi -> left);
          
          if (fi -> right != NULL)
            q.push(fi -> right);
        }
      }
      
      if (index%2)
      {
        if (size != flag)
          return false;
      }
      else
      {
        if (size != flag)
          return false;
      }
      index++;
    }
    return true;
  }
public:
    bool isEvenOddTree(TreeNode* root) {
        return Helper(root);
    }
};