// C++ implementation to count pairs from two
#include <bits/stdc++.h>
using namespace std;

// structure of a node of BST
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

void insert(Node ** tree, int val)
{
    Node *temp = NULL;
    if(!(*tree))
    {
        temp = new Node(val);
        *tree = temp;
        return;
    }

    if(val < (*tree)->data)
    {
        insert(&(*tree)->left, val);
    }
    else if(val > (*tree)->data)
    {
        insert(&(*tree)->right, val);
    }

}

int countPairs(Node* root1, Node* root2, int x);

// Driver code
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        Node* root1 = NULL;
        Node* root2 = NULL;
        int n1, n2, k;
        cin>>n1;
        for(int i=0; i<n1; i++)
        {
            cin>>k;
            insert(&root1, k);
        }
        cin>>n2;
        for(int i=0; i<n2; i++)
        {
            cin>>k;
            insert(&root2, k);
        }
        int s;
        cin>>s;
        cout<<countPairs(root1, root2, s)<<"\n";
    }
    return 0;
}


// } Driver Code Ends


//User function Template for C++
/*Structure of the Node of the BST is as
struct Node {
	int data;
	Node* left, *right;
};*/
// You are required to complete this function
bool searchr(Node* root,int x){
    if(root== NULL)
        return true;
    Node* cur=root;
    while(cur!=NULL){
        if(cur->data==x)
            return true;
        else if(cur->data>x){
            cur=cur->left;
        }
        else{
            cur=cur->right;
        }
    }
    return false;
}
int c=0;
void inoder(Node* root1,Node*root2,int x){
    if(root1==NULL)
        return ;
    inoder(root1->left,root2,x);
    if(searchr(root2,x-root1->data)==true){
        c=c+1;
        
    }
    inoder(root1->right,root2,x);
    
}
int countPairs(Node* root1, Node* root2, int x)
{
    // Code here
    c=0;
    inoder(root1,root2,x);
    return c;
}