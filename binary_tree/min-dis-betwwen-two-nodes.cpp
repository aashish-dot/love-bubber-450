#include <bits/stdc++.h>

using namespace std;

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
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

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

int findDist(Node *, int, int);

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Node *root = buildTree(treeString);
        int n1, n2;
        scanf("%d %d ", &n1, &n2);
        cout << findDist(root, n1, n2) << "\n";
    }
    return 0;
}// } Driver Code Ends


/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

/* Should return minimum distance between a and b
   in a tree with given root*/
int dis(Node* root,int x){
    if(root==NULL)
        return 0;
    if(root->data==x)
        return 1;
    int lh=dis(root->left,x);
    int rh=dis(root->right,x);
    if(lh==0&&rh==0)
        return 0;
    return max(lh,rh)+1;
}
 Node* lca(Node* root ,int n1 ,int n2 )
    {
       //Your code here 
    if(root==NULL)
        return root;
    if(root->data==n1||root->data==n2)
        return root;
    Node* lca1=lca(root->left,n1,n2);
    Node* lca2=lca(root->right,n1,n2);
    if(lca1&&lca2){
        return root;
    }
    if(lca1)
        return lca1;
    else
        return lca2;
    }
int findDist(Node* root, int a, int b) {
    // Your code here
    Node* cur=lca(root,a,b);
    int m= dis(root,a);
    int n=dis(root,b);
    int p=dis(root,cur->data);
    return m+n-2*p;
}