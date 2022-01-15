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
  int answer = INT_MIN;
  
  int get_height(TreeNode* root)
  {
    if (root == NULL)
      return 0;
    
    return 1 + max(get_height(root -> left),get_height(root -> right));
  }
    
  void get_diameter (TreeNode *root)
  {
    if (root == NULL)
      return;
    
    int lh = get_height(root -> left);
    int rh = get_height(root -> right);
    
    answer = max(answer, lh+rh);
    
    get_diameter(root ->left);
    get_diameter(root -> right);
  }
  
  
    int diameterOfBinaryTree(TreeNode* root) {
        get_diameter (root);
      return answer;
    }
};