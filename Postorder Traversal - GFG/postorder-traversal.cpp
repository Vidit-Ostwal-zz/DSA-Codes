// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

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
    Node* root = newNode(stoi(ip[0]));
        
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
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
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
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}

/* Computes the number of nodes in a tree. */
vector <int> postOrder(struct Node* root);

/* Driver program to test size function*/
int main()
{
  int t;
  cin>>t;
  getchar();
  while (t--)
  {
  	 string inp;
     getline(cin, inp);
     struct Node* root = buildTree(inp);

     vector <int> res = postOrder(root);
     for (int i = 0; i < res.size (); i++)
        cout << res[i] << " ";
     cout << endl;
  }
  return 0;
}// } Driver Code Ends


//User function Template for C++

/* A binary tree node has data, pointer to left child
   and a pointer to right child  
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
}; */

/*
Time Complexity = O(N) N is number of nodes we will visit all the nodes
Space Complexity = O(N) vector in which we are storing */
vector<int> iterative_solution (Node* root)
{
    vector<int> temp_vector;
    stack<Node*> st;
    stack<Node*> st1;
    st.push(root);
    while (!st.empty())
    {
        root = st.top();
        st.pop();
        st1.push(root);
        /*
        left and right should not be null as it does not have any data and also it does not 
        point to anything.
        */
        if (root -> left != NULL)
        st.push(root -> left) ;
        
        if (root -> right != NULL)
        st.push(root -> right);
        
        
    }
    while (!st1.empty())
    {
        temp_vector.push_back(st1.top() -> data);
        st1.pop();
    }
    
    return temp_vector;
}


/*
Time Complexity = O(N) N is number of nodes we will visit all the nodes
Space Complexity = O(N) Recursion stack Space and vector in which we are storing */
void recursive_solution(Node *root, vector<int> &temp_vector)
{
    if (root == NULL)
    return;
    
    
    recursive_solution(root -> left,temp_vector);
    recursive_solution(root -> right,temp_vector);
    temp_vector.push_back(root -> data);
}
//Function to return a list containing the postorder traversal of the tree.
vector <int> postOrder(Node* root)
{
  vector<int> temp_vector;
  recursive_solution(root,temp_vector);
  return iterative_solution(root);
}
