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
  unordered_map<TreeNode*,int> u1_true;
  unordered_map<TreeNode*,int> u1_false;
  
  int recursive_way(TreeNode* root, bool flag)
  {
    if (root  == NULL )
      return 0;
    
    
    
    if (flag)
    {
      if (u1_true.find(root) != u1_true.end())
        return u1_true[root];
      
      return u1_true[root] = recursive_way(root -> left, !flag) + recursive_way(root -> right,!flag);
    }
    else
    {
      if (u1_false.find(root) != u1_false.end())
        return u1_false[root];
      
      int option1 = root -> val + recursive_way(root -> left,true) + recursive_way(root -> right,true);
      int option2 = recursive_way(root -> left,false) + recursive_way(root -> right,false);
      
      return u1_false[root] = max(option1,option2);
    }
  }
public:
    int rob(TreeNode* root) {
      if (root == NULL)
        return 0;
      
        return recursive_way(root, false);
    }
};