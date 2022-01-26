/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == NULL)
          return "";
      
      queue<TreeNode*> q;
      q.push(root);
      string answer = "";
      while(!q.empty())
      {
        root = q.front();
        q.pop();
        
        if (root == NULL)
          answer += "#,";
        else
        {
          answer += to_string(root->val);
          answer+= ',';
           q.push(root->left);
          q.push(root->right);  
        }
      }
      return answer;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.length() == 0)
          return NULL;
      
      stringstream s(data);
      string str;
      getline(s,str,',');
      
      TreeNode* root = new TreeNode(stoi(str));
      
      queue<TreeNode*> q;
      q.push(root);
      
      while (!q.empty())
      {
        TreeNode* temp = q.front();
        q.pop();
        
        getline(s,str,',');
        if (str == "#")
        {
          temp->left = NULL;
        }
        else
        {
          TreeNode* left1 = new TreeNode(stoi(str));
          temp->left = left1;
          q.push(left1);          
        }
        
        getline(s,str,',');
        if (str == "#")
        {
          temp->right = NULL;
        }
        else
        {
          TreeNode* right1 = new TreeNode(stoi(str));
          temp->right = right1;
          q.push(right1);          
        }
      }
      return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));