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
  
  /* Recursive approach 
  N = number of nodes in binary tree
  Time Complexity = O(N)
  Space Complexity = O(N) Height of recursion tree
  */
  int get_height(TreeNode* root)
  {
    if (root == NULL)
      return 0;
    
    return 1 + max(get_height(root -> left),get_height(root -> right));
  }
  
  /*Level Order Search*/
  /* Iterative approach 
  N = number of nodes in binary tree
  Time Complexity = O(N)
  Space Complexity = O(1)
  */
  int level_order (TreeNode* root)
  {
    queue<TreeNode*> q;
    q.push(root);
    int count = 0;
    while (!q.empty())
    {
      int size = q.size();
      for (int i = 0; i < size ;i++)
      {
        TreeNode* temp = q.front();
        q.pop();
        if (temp -> left != NULL)
          q.push(temp -> left);
        
        if (temp -> right != NULL)
          q.push(temp -> right);
      }
      count++;
    }
    return count;
  }
  
    int maxDepth(TreeNode* root) {
      if (root == NULL)
      {
        return 0;
      }
        return get_height(root);
    }
};