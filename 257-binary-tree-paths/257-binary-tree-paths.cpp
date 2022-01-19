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
  string get_string(vector<int> temp_vector)
  {
    string answer = to_string(temp_vector[0]);
    
    for (int i = 1 ; i < temp_vector.size();i++)
    {
      answer += "->";
      answer += to_string(temp_vector[i]);
    }
    return answer;
  }
  
  
  void getpath(TreeNode* A,vector<int>& temp_vector,vector<string>&final_vector)
    {
        if (A == NULL)
        return ;

        temp_vector.push_back(A->val);

        if (A->left == NULL && A-> right == NULL)
        {
          final_vector.push_back(get_string(temp_vector));
          temp_vector.pop_back();
          return;
        }
  
        getpath(A->left,temp_vector,final_vector);
        getpath(A->right,temp_vector,final_vector);
        
        temp_vector.pop_back();
    }
  
    vector<string> binaryTreePaths(TreeNode* root) {
      vector<string> final_vector;  
      vector<int> temp_vector;
        if (root == NULL)
        return final_vector;
      
      
        getpath(root,temp_vector,final_vector);
        return final_vector;
    }
};