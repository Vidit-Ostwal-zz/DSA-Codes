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
  void recursive_solution(TreeNode *root, vector<int> &final_vector)
  {
    if (root == NULL)
      return ;
    
    final_vector.push_back(root -> val);
    recursive_solution(root -> left,final_vector);
    recursive_solution(root -> right,final_vector);
  }
  
  vector<int> iterative_solution(TreeNode* root)
  {
    vector<int> final_vector;
    if (root == NULL)
      return final_vector;
    
    stack <TreeNode*> st;
    st.push(root);
    
    while (!st.empty())
    {
      root = st.top();
      st.pop();
      final_vector.push_back(root -> val);
      
       if (root -> right != NULL)
        st.push(root -> right);
      
      if (root -> left != NULL)
        st.push(root -> left);
      
     
    }
    return final_vector;
  }
  
  
    vector<int> preorderTraversal(TreeNode* root) {
        /*vector<int> final_vector;
      recursive_solution(root, final_vector);*/
      return iterative_solution(root);
    }
};