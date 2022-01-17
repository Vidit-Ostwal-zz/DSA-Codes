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
  
  /*
  Time and Space Complexity = O(N)*/
  int get_height(TreeNode* root)
  {
    if (root == NULL)
      return 0;
    
    int left = get_height(root -> left);
    int right = get_height(root -> right);
    
    answer =  max(answer,left+right);
    return 1 + max(left,right);
  }
  
  /*
  Time Complexity = O(N^2) Iteration on each nodes and then getting height from each one
  Space Compleixty = O(N) Recursion Stack Space
  not Acceptabe
  */
  /*void get_diameter (TreeNode *root)
  {
    if (root == NULL)
      return;
    
    int lh = get_height(root -> left);
    int rh = get_height(root -> right);
    
    answer = max(answer, lh+rh);
    
    get_diameter(root ->left);
    get_diameter(root -> right);
  }
  */
  
  
    int diameterOfBinaryTree(TreeNode* root) {
        get_height(root);
      return answer;
    }
};