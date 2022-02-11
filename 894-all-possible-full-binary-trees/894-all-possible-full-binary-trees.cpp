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
  /*The fact that there are 2L - 1 total nodes in a full binary tree means that the number of nodes in a full binary tree is always odd, so you can't create a full binary tree with 6 nodes.*/
  
  vector<TreeNode*> makeTree(int n)
  {
    if (n == 1)
    {
      TreeNode* root = new TreeNode(0);
      return {root};
    }
    
    vector<TreeNode*> final_vector;
    for (int i = 2; i <= n; i = i+2)
    {
      vector<TreeNode*> left = makeTree(i-1);
      vector<TreeNode*> right = makeTree(n-i);
      
      for (int i =0 ;i < left.size();i++)
        for (int j = 0; j < right.size(); j++)
        {
          TreeNode* root = new TreeNode(0);
          root -> left = left[i];
          root -> right = right[j];
          final_vector.push_back(root);
        }
    }
    return final_vector;
  }
  
    vector<TreeNode*> allPossibleFBT(int n) {
        return makeTree(n);
    }
};