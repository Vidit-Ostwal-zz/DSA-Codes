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
  vector<int> right_level_order_search(TreeNode *root)
{
    vector<int> final_vector;
    if (root == NULL)
    return final_vector;
    
    queue<TreeNode*> q;
    q.push(root);
    
    while (!q.empty())
    {
        int size = q.size();
        
        for (int i= 0; i< size; i++)
        {
            root = q.front();
            q.pop();
            
            if (root -> left != NULL)q.push(root -> left);
            if (root -> right != NULL)q.push(root -> right);
            
            if (i == size-1)
            {
                final_vector.push_back(root->val);
            }
        }
    }
    return final_vector;
}
  
  
    vector<int> rightSideView(TreeNode* root) {
        return right_level_order_search(root);
    }
};