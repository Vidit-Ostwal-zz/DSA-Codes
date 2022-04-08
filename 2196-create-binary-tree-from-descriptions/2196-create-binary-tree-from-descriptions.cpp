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
  TreeNode* make_tree(int val, unordered_map<int,vector<vector<int>>> parent)
  {
    TreeNode* root = new TreeNode(val);
    vector<vector<int>> temp = parent[val];
    
    for (int i = 0; i < temp.size(); i++)
    {
      if (temp[i][2] == 1)
        root -> left = make_tree(temp[i][1],parent);
      else
        root -> right = make_tree(temp[i][1],parent);
    }
    return root;
  }
  
public:
    TreeNode* createBinaryTree(vector<vector<int>>& desc) {
//         sort(desc.begin(),desc.end());
      
      unordered_map<int,vector<vector<int>>> parent;
      unordered_map<int,int> mp;
      for (int i = 0; i < desc.size();i++)
      {
        mp[desc[i][0]]++;
        parent[desc[i][0]].push_back(desc[i]);
      }
      
      for (int i = 0; i < desc.size();i++)
      {
        if (mp.find(desc[i][1]) != mp.end())
          mp.erase(desc[i][1]);
      }
      // cout << mp.size() << endl;
      int root_val = mp.begin() -> first ;
      
      TreeNode* root = new TreeNode(root_val);
      queue<TreeNode*> q;
      q.push(root);
      
      while (!q.empty())
      {
        TreeNode* temp = q.front();
        q.pop();
        
        int p = temp->val;
        
        for (int i = 0; i < parent[p].size(); i++)
        {
          if (parent[p][i][2] == 1)
            temp -> left = new TreeNode(parent[p][i][1]);
          else
            temp -> right = new TreeNode(parent[p][i][1]);
        }
        
        if (temp -> left != NULL)
          q.push(temp -> left);
        if (temp -> right != NULL)
          q.push(temp -> right);
      }
      return root;
    }
};