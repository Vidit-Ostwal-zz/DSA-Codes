/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*> mp;
        
        queue<TreeNode*> q;
        q.push(root);
        mp[root] = NULL;
        while (!q.empty())
        {
    
            TreeNode* temp = q.front();
            q.pop();
            if (temp-> left != NULL)
            {
                q.push(temp->left);
                mp[temp->left] = temp;
            }
            if (temp-> right != NULL)
            {
                q.push(temp->right);
                mp[temp->right] = temp;
            }
        }
        unordered_map<TreeNode*,bool> visited;
        queue<TreeNode*> q1;
        q1.push(target);
      
        while(k > 0)
        {
          int size = q1.size();
          
          for (int i = 0; i < size;i++)
          {
  
            TreeNode* temp = q1.front();
            q1.pop();
            
            visited[temp] = true;
            
            if (temp -> left != NULL && !visited[temp->left]) q1.push(temp-> left);
            if (temp -> right != NULL && !visited[temp->right]) q1.push(temp-> right);
            if (mp[temp] != NULL && !visited[mp[temp]]) q1.push(mp[temp]);
          }
          k--;
        }
        vector<int> answer;
        while(!q1.empty())
        {
            answer.push_back(q1.front()->val);
            q1.pop();
        }
        sort(answer.begin(),answer.end());
        return answer;
    }
};