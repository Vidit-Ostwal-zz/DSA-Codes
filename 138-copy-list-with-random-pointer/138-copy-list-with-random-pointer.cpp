/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
      if (head == NULL)
        return NULL;
      int index = 0;
      unordered_map<Node*,int> mp;
      unordered_map<int,Node*> mp1;
      Node* temp = head;
      
      Node* root = new Node(INT_MIN);
      Node* temp1 = root;
      while (temp != NULL)
      {
        temp1 -> val = temp-> val;
        mp1[index] = temp1;
      
        
      
        mp[temp] = index;
        temp = temp -> next;
        
        if (temp)
        {
          temp1 -> next = new Node(INT_MIN);
          temp1 = temp1 -> next;
        }
          
        index++;
      }
      temp1 = NULL;
      
      temp = head;
      temp1 = root;
      
      while (temp != NULL)
      {
        if (temp -> random == NULL)
          temp1 -> random = NULL;
        else
        {
          int id = mp[temp->random];
          temp1-> random = mp1[id];
        }
        temp = temp -> next;
        temp1 = temp1-> next;
      }
      return root;
    }
};