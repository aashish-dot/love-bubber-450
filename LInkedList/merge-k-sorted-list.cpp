// C++ program to merge k sorted arrays of size n each
#include <bits/stdc++.h>
using namespace std;

// A Linked List node
struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};

/* Function to print nodes in a given linked list */
void printList(Node* node)
{
	while (node != NULL)
	{
		printf("%d ", node->data);
		node = node->next;
	}
	cout<<endl;
}

 // } Driver Code Ends
/*Linked list Node structure

struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};
*/ 

class Solution{
  public:
    //Function to merge K sorted linked list.
   Node* SortedMerge(Node* a, Node* b)
    {
    	Node* result = NULL;
    
    	//base cases when either of two lists is null.
    	if (a == NULL)
    		return (b);
    	else if(b == NULL)
    		return (a);
    
        //comparing data in both lists and storing the smaller in result and
        //recursively calling the SortedMerge function for next node in result.
    	if(a->data <= b->data)
    	{
    		result = a;
    		result->next = SortedMerge(a->next, b);
    	}
    	else
    	{
    		result = b;
    		result->next = SortedMerge(a, b->next);
    	}
        //returning the resultant list.
    	return result;
    }
    
    //Function to merge K sorted linked list.
    Node* mergeKLists(Node* arr[], int K)
    {
        int N = K;
        int last=N-1; 
    	while (last != 0)
    	{
    		int i = 0, j = last;
    		while (i < j)
    		{
    			//calling SortedMerge function to merge two different list into
    			//one list which has sorted elements.
    			arr[i] = SortedMerge(arr[i], arr[j]);
    
    			//going for the next pair of lists.
    			i++, j--;
    
    			//if all pairs are merged, we update the last.
    			if (i >= j)
    				last = j;
    		}
    	}
        //returning the merged list.
    	return arr[0];
    }
};



// { Driver Code Starts.
// Driver program to test above functions
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
	   int N;
	   cin>>N;
       struct Node *arr[N];
       for(int j=0;j<N;j++)
        {
           int n;
           cin>>n;

           int x;
           cin>>x;
           arr[j]=new Node(x);
           Node *curr = arr[j];
           n--;

           for(int i=0;i<n;i++)
           {
               cin>>x;
               Node *temp = new Node(x);
               curr->next =temp;
               curr=temp;
           }
   		}
   		Solution obj;
   		Node *res = obj.mergeKLists(arr,N);
		printList(res);

   }

	return 0;
}
  // } Driver Code Ends