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
  void Flip (TreeNode* root)
  {
    TreeNode* temp = root -> left;
    root -> left = root -> right;
    root -> right = temp;
    return;
  }
  
  vector<int> answer;
  int index = 0;
  bool can_we (TreeNode* root, vector<int> A,vector<bool>&visited)
  {
    if (root == NULL)
      return true;
    
    if (index == A.size())
      return true;
  
    if (root -> val != A[index])
      return false;
    
    visited[index] = true;
    index++;
    if (root -> left != NULL && root -> right != NULL)
    {
      if (root -> left -> val == A[index])
        return can_we(root -> left,A,visited) && can_we(root -> right,A,visited) ;
      else
      {
        Flip(root);
        answer.push_back(root->val);
        return can_we(root -> left,A,visited) && can_we(root -> right,A,visited) ;
      }
    }
    if (root -> left == NULL)
      return can_we(root ->right,A,visited);
    return can_we(root -> left,A,visited);
  }
public:
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
      vector<bool>visited(voyage.size(),false);
       bool flag = can_we(root,voyage,visited);
      
      if (flag)
        return answer;
      return {-1};
    }
};