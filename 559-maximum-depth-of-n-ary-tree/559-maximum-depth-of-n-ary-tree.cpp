/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
  int get_height(Node* root)
  {
    if (root == NULL)
      return 0;
    
    int answer = 0;
    vector<Node*> temp = root -> children;
    
    if (temp.size() == 0)
      return 1;
    
    for (int i = 0; i <  temp.size(); i++)
      answer = max(answer,1 + get_height(temp[i]));
    
    return answer;
  }
public:
    int maxDepth(Node* root) {
        if (root == NULL)
          return 0;
      
      return get_height(root);
    }
};