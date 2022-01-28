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
  TreeNode* findgreatestelement (TreeNode* root)
  {
    while (root -> right != NULL)
    {
      root = root-> right;
    }
    return root;
  }
  
  TreeNode* Helper (TreeNode* root)
  {
    if (root -> left == NULL)
      return root -> right;
    
    if (root -> right == NULL)
      return root-> left;
    
    TreeNode* left_greatest = findgreatestelement(root->left);
    left_greatest -> right = root -> right;
    
    return root->left;
  }
  
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
      /*Zero Elements to be deleted*/  
      if (root == NULL)
          return NULL;
      
      if (root->val == key)
        return Helper(root);
      
      TreeNode* dummy = root;
      while (root != NULL)
      {
        if (root->val > key)
        {
          if (root-> left != NULL && root->left->val == key)
          {
            root->left = Helper(root->left);
            break;
          }
          else
          {
            root = root-> left;
          }
        }
        else
        {
          if (root -> right != NULL && root->right->val == key)
          {
            root->right = Helper(root->right);
            break;
          }
          else
          {
            root = root -> right;
          }
        }
      }
      return dummy;
    }
};