
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
    
    Node* buildt(int in[],int pre[], int n,int &preindex,int is,int ie){
        if(is>ie)
            return NULL;
        Node* root=new Node(pre[preindex++]);
        int inindex;
        for(int i=is;i<=ie;i++){
            if(in[i]==root->data){
                inindex=i;
                break;
            }
        }
        root->left=buildt(in,pre,n,preindex,is,inindex-1);
        root->right=buildt(in,pre,n,preindex,inindex+1,ie);
        return root;
        
        
    }
    Node* buildTree(int in[],int pre[], int n)
    {
        // Code here
        int preindex=0;
        return buildt(in,pre,n,preindex,0,n-1);
        
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