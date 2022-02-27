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
  /*Indexing of each node has been done and stored in Hash Maps*/
  void preorder_traversal(TreeNode *root, unordered_map<int,vector<long long >>& mp ,int level, int pre_index,bool flag)
{
  if (root == NULL)
    return;
    
    if (flag)
      mp[level].push_back((long long)pre_index*2+1);
    else
      mp[level].push_back((long long)pre_index*2+2);
    
    preorder_traversal(root->left,mp,level+1,mp[level][mp[level].size()-1] - 1,true);
    preorder_traversal(root->right,mp,level+1,mp[level][mp[level].size()-1] - 1,false);
    
}
public:
    int widthOfBinaryTree(TreeNode* root) {
        unordered_map<int,vector<long long >> mp;
      int level = 1;
        mp[1].push_back(0);
      
        preorder_traversal(root->left,mp,2,0,true);
        preorder_traversal(root->right,mp,2,0,false);
      
      int answer = INT_MIN;
      while (mp.find(level) != mp.end())
      {
        long long  smallest = mp[level][0];
        long long  longest = mp[level][mp[level].size()-1];
        
        answer = ((longest-smallest+1) > answer) ? longest-smallest+1 : answer; 
        
        level++;
      }
        return answer;
    }
};