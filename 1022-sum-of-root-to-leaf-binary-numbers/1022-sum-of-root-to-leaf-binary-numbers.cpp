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
  int smart_approach(TreeNode* root, int sum, int height)
  {
    if (root == NULL)
      return 0;
    
    if (root -> left == NULL && root -> right == NULL)
    {
      cout << sum*2 + (root -> val) << endl;
      return sum*2 + (root -> val);
    }
    
    int left = smart_approach(root ->left, sum*2 + root->val,height+1);
    int right = smart_approach(root -> right,sum*2 + root->val,height+1);
    
    return left+ right;
  }
public:
    int sumRootToLeaf(TreeNode* root) {
        return smart_approach(root,0,0);
    }
};