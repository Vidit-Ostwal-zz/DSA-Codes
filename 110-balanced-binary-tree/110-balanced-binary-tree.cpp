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
  
  /*Updated height function to return height from a node if after that node tree is balance otherwise return -1;*/
  /*Time Complexity = O(N)
  Sapce Complexity = O(N) Recursion stack Space*/
  int get_height(TreeNode* root)
  {
    if (root == NULL)
      return 0;
    
    int left = get_height(root -> left);
    int right = get_height(root -> right);
    
    if (left == -1 || right == -1)
      return -1;
    
    if (abs (left - right) > 1)
      return -1 ;
    return 1 + max(left,right);
  }
  
  /*bool  check(TreeNode* root)
  {
    if (root == NULL)
      return true;
  
    int left = get_height (root -> left);
    int right = get_height(root -> right);
    
    if (abs (left - right) <= 1 && check (root -> left) && check (root -> right))
      return true;
    
    return false;
  }
  */
    bool isBalanced(TreeNode* root) {
        if (root == NULL)
          return true;
      
      return (get_height(root) == -1) ? false : true;
    }
};