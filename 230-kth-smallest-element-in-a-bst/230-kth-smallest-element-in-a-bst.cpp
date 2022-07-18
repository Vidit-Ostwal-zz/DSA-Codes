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
    
    void f(TreeNode* node, int& cnt, int k, int& y){
        
        if(node == NULL){
            return;
        }
        
        
        f(node->left,cnt,k,y);
        cnt++;
        if(cnt == k){
            y = node->val;
            return;
        }
        f(node->right,cnt,k,y);
        
    }
    
    int kthSmallest(TreeNode* root, int k) {
        
        int cnt = 0;
        int y = -1;                    // y = kth small element
        f(root,cnt,k,y);
        return y;
    }
};