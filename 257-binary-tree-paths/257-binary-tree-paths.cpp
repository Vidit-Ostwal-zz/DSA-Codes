class Solution {
public:
    void f(TreeNode* node, vector<string>& ans,string ds){
        
        
        if(node == NULL)
            return;
        
        //leaf node found
        if(node->left == NULL && node->right == NULL){
            ds = ds + to_string(node->val);
            ans.push_back(ds);
            return;
        }
        
              
        ds = ds + to_string(node->val);
        ds = ds + "->";
        
        
        f(node->left,ans,ds);
       
        f(node->right,ans,ds);
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ans;
        string ds;
        f(root,ans,ds);
        return ans;
    }
};