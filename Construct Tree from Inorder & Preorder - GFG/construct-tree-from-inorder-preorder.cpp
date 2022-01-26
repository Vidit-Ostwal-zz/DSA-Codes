// { Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

 // } Driver Code Ends


/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    public:
    unordered_map<int,int> mp;
  int i = 0;
  
  Node* make_tree(int preorder[],int inorder[], int s,int e)
  {
    if (s>e)
      return NULL;
    
    Node* root = new Node(preorder[i++]);
    int root_index = mp[root->data];
    
    root->left = make_tree(preorder,inorder,s,root_index-1);
    root-> right = make_tree(preorder,inorder,root_index+1,e);
    
    return root;
  }

    Node* buildTree(int inorder[],int preorder[], int n)
    {
        for (int i=  0; i < n;i++)
      {
        mp[inorder[i]] = i;
      }
      
      Node* root = make_tree(preorder,inorder,0,n-1);
      
      return root;
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}
  // } Driver Code Ends