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
class FindElements {
  unordered_map<int,int>map;
  void Recoverit (TreeNode* root,int index)
  {
    if (root == NULL)
      return;
    
    root -> val = index;
    map[index]++;
    Recoverit(root -> left,index*2+1);
    Recoverit(root -> right, index*2+2);
  }
public:
    FindElements(TreeNode* root) {
        Recoverit(root,0);
    }
    
    bool find(int target) {
        if (map.find(target) != map.end())
          return true;
      return false;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */