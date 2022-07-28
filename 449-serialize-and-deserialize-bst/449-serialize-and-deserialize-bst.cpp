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
  string inorder = "";
 void inorder_traversal(TreeNode* root)
 {
  if (root == NULL)
   return;
   
  if (inorder.length())
    inorder += " "+ to_string(root -> val);
   else
     inorder += to_string(root -> val);
   
    // push_back(root -> val);
  inorder_traversal(root -> left);
  inorder_traversal(root -> right);
 }
  
  TreeNode* make_tree (vector<int>& vect, int left, int right)
  {
    if (left == right)
      return new TreeNode(vect[left]);
    
    else if (left > right)
      return NULL;
    
    int mid = left;
    while (mid <= right && vect[mid] <= vect[left])
      mid++;
    
    TreeNode* root = new TreeNode(vect[left]);
    
    root -> left = make_tree(vect,left+1,mid-1);
    root -> right = make_tree(vect,mid,right);
    return root;
  }
  public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        inorder_traversal(root);
      // cout << inorder << endl;
      return inorder;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
      
      if (data.length() == 0)
        return NULL;
      
      vector<int> vect;
      
      string temp = "";
        for (int i = 0; i < data.length(); i++)
        {
          if (data[i] == ' ')
          {
            vect.push_back(stoi(temp));
            temp = "";
          }
          else
            temp += data[i];
        }
      
       vect.push_back(stoi(temp));
      // cout << vect.size() << endl;
      return make_tree(vect,0,vect.size()-1);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;