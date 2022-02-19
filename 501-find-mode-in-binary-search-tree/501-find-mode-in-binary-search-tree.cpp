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
  unordered_map<int,int> mp;
 void inorder_traversal(TreeNode* root)
 {
  if (root == NULL)
   return;
   
  inorder_traversal(root -> left);
  mp[root -> val]++;
  inorder_traversal(root -> right);
 }
public:
    vector<int> findMode(TreeNode* root) {
      inorder_traversal(root);
      int maxi = INT_MIN;
      
      for (auto it = mp.begin(); it != mp.end(); it++)
        maxi = max(maxi,it -> second);
      
      vector<int> answer;
      for (auto it = mp.begin(); it != mp.end(); it++)
        if (it -> second == maxi)
          answer.push_back(it -> first);
      
      return answer;
    }
};