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
  vector<TreeNode*> makeTree(int st_index, int end_index, vector<int> vect)
  {
    if (st_index >= end_index)
    {
      TreeNode *root = NULL;
      return {root};
    }
    
    vector<TreeNode*> final_vector;
    for (int i = st_index ; i < end_index ; i++)
    {
      vector<TreeNode*> left = makeTree(st_index,i,vect);
      vector<TreeNode*> right = makeTree(i+1,end_index,vect);
      
      for (int k =0 ;k < left.size();k++)
        for (int j = 0; j < right.size(); j++)
        {
          TreeNode* root = new TreeNode(vect[i]);
          root -> left = left[k];
          root -> right = right[j];
          final_vector.push_back(root);
        }
    }
    return final_vector;
  }
public:
    vector<TreeNode*> generateTrees(int n) {
      vector<int> vect(n);
      for (int i = 1; i <= n; i++)
        vect[i-1] = i;
      
        return makeTree(0,n,vect);
    }
};