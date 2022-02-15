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
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> final_answer;
      
      if (root == NULL) return final_answer;
      queue<Node*> q;
      q.push(root);
      
      while(!q.empty())
      {
        int size = q.size();
        vector<int> answer;
        for (int i = 0; i < size; i++)
        {
          Node* temp = q.front();
          q.pop();
          
          answer.push_back(temp -> val);
          
          vector<Node*>temp_vector = temp ->children;
          for (int i = 0; i < temp_vector.size(); i++)
            q.push(temp_vector[i]);
        }
        final_answer.push_back(answer);
      }
      return final_answer;
    }
};