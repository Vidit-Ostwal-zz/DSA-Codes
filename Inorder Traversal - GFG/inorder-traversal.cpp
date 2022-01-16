// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


 // } Driver Code Ends
/* A binary tree node has data, pointer to left child
   and a pointer to right child
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
}; */

class Solution {
  public:
  /*
Time Complexity = O(N) N is number of nodes we will visit all the nodes
Space Complexity = O(N) Recursion stack Space and vector in which we are storing */
void recursive_solution(Node *root, vector<int> &temp_vector)
{
    if (root == NULL)
    return;
    
    recursive_solution(root -> left,temp_vector);
    temp_vector.push_back(root -> data);
    recursive_solution(root -> right,temp_vector);
}

/*
Time Complexity = O(N) N is number of nodes we will visit all the nodes
Space Complexity = O(N) vector in which we are storing */
vector<int> iterative_solution (Node* root)
{
    vector<int> temp_vector;
    stack<Node*> st;
    
    while (root != NULL || !st.empty())
    {
        while (root != NULL)
        {
            st.push(root);
            root = root -> left;
        }
        
        root = st.top();
        temp_vector.push_back( root ->data);
        st.pop();
        root = root -> right;
    }
    return temp_vector;
}


    // Function to return a list containing the inorder traversal of the tree.
    vector<int> inOrder(Node* root) {
        /*vector<int> temp_vector;
        recursive_solution(root,temp_vector);
        */
        return iterative_solution(root);
    }
};

// { Driver Code Starts.

// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);
        Node* root = buildTree(s);

        Solution ob;
        vector<int> res = ob.inOrder(root);
        for (int i = 0; i < res.size(); i++) cout << res[i] << " ";
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends