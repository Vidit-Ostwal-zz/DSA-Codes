// space complexity=O(1)
class Solution {
    TreeNode* n1=NULL,*n2;
    void inorder(TreeNode* root,TreeNode* &prev){
        if(!root)return;
        inorder(root->left,prev);
        if(prev!=NULL&&prev->val>root->val){
            if(n1==NULL)n1=prev,n2=root; // if n1==NULL means we encounter first cases
            else{ n2=root;return;} // else this is second case we have first  wrong node in n1, now update n2
        }
        prev=root; // update prev
        inorder(root->right,prev);
    }
public:
    void recoverTree(TreeNode* root) {
        TreeNode* prev=NULL;
        inorder(root,prev);
        swap(n1->val,n2->val);
    }
};