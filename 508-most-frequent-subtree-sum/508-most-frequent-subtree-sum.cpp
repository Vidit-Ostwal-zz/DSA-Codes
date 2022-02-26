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
  int get_subtree_sum(TreeNode* root)
  {
    if (root == NULL)
      return 0;
    
    int left = get_subtree_sum(root ->left);
    int right = get_subtree_sum(root -> right);
    
    mp[left+ right + root ->val]++;
    
    return left+right+root->val;
  }
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
      
      if (root == NULL)
        return {};
      
       get_subtree_sum (root);
      auto it = mp.begin();
      cout << "Here" << endl;
      
      int maxi = INT_MIN;
      while (it != mp.end())
      {
        maxi = max(maxi,it ->second);
        it++;
      }
      cout << "Here" << endl;
      vector<int> answer;
      
      auto it1 = mp.begin();
      while (it1 != mp.end())
      {
        if (it1 -> second == maxi)
          answer.push_back(it1 -> first);
        
        it1++;
      }
      return answer;
    }
};