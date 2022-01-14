// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
}; 

// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}

 // } Driver Code Ends
//User function template for C++

/*
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

/* Recursive approach 
  N = number of nodes in binary tree
  Time Complexity = O(N)
  Space Complexity = O(N) Height of recursion tree
  */
  int get_height(Node* root)
  {
    if (root == NULL)
      return 0;
    
    return 1 + max(get_height(root -> left),get_height(root -> right));
  }
  
  /*Level Order Search*/
  /* Iterative approach 
  N = number of nodes in binary tree
  Time Complexity = O(N)
  Space Complexity = O(1)
  */
  int level_order (Node* root)
  {
    queue<Node*> q;
    q.push(root);
    int count = 0;
    while (!q.empty())
    {
      int size = q.size();
      for (int i = 0; i < size ;i++)
      {
        Node* temp = q.front();
        q.pop();
        if (temp -> left != NULL)
          q.push(temp -> left);
        
        if (temp -> right != NULL)
          q.push(temp -> right);
      }
      count++;
    }
    return count;
  }
  
class Solution{
    public:
    //Function to find the height of a binary tree.
    int height(struct Node* node){
        return level_order(node);
    }
};

// { Driver Code Starts.
int main()
{
    int t;
	scanf("%d ",&t);
    while(t--)
    {
        string treeString;
		getline(cin,treeString);
		Node* root = buildTree(treeString);
        Solution ob;
		cout<<ob.height(root)<<endl;
    }
    return 0;
}  // } Driver Code Ends