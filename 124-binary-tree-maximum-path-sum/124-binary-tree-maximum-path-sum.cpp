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
  
  int findmax(TreeNode* root)
  {
    if (root == NULL)
      return 0;
    
    /*Get left and right sum*/
    int left = findmax(root -> left);
    int right = findmax(root -> right);
    
    /*
    1> Only till this root 
    2> Either of the children
    3> Answer including both children
    */
    
    /*Returing thing max root coming from upward should stop at that node of if going forward should take at atmost one children*/
    int max_single = max(root -> val, root -> val + max(left,right));
    answer = max(answer,max(max_single,root->val + left + right));
    return max_single;
  }
  
  
    int maxPathSum(TreeNode* root) {
      findmax(root);
      return answer;
      
    }
};