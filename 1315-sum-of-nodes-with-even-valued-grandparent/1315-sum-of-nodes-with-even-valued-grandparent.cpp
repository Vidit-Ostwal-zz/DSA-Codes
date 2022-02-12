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
    int sumEvenGrandparent(TreeNode* root) {
        int answer = 0;
      
      if (root == NULL)
        return 0;
      
      if (root -> val % 2 == 0)
      {
        if (root -> left != NULL)
        {
          answer += (root -> left -> left != NULL) ? root -> left ->left ->val : 0;
          answer += (root -> left -> right != NULL) ?  root -> left ->right ->val : 0;
        }
        if (root -> right != NULL)
        {
          answer += (root -> right -> left != NULL) ? root -> right ->left ->val : 0;
          answer += (root -> right -> right != NULL) ? root -> right ->right ->val : 0;
        }
      }
      answer += sumEvenGrandparent(root -> left);
      answer += sumEvenGrandparent(root -> right);
        
      return answer;
    }
};