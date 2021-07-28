#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};


void print(Node *root)
{
    Node *temp = root;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}



 // } Driver Code Ends
/*

The structure of linked list is the following

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

class Solution
{
    public:
    Node* rev(Node* head){
    if(head==NULL||head->next==NULL){
        return head;
    }
    Node* cur=head,*pre=NULL;
    while(cur!=NULL){
        Node* next=cur->next;
        cur->next=pre;
        pre=cur;
        cur=next;
    }
    return pre;
}
    Node *compute(Node *head)
    {
    if(head==NULL||head->next==NULL){
        return head;
    }
    head=rev(head);
     
     
   
    Node*temp=new Node(head->data);
    Node* head1=temp;
    int mx=head->data;
    Node* cur=head->next;
    while(cur!=NULL){
        if(mx<=cur->data){
            temp->next=new Node(cur->data);
            mx=cur->data;
            temp=temp->next;
        }
        
        cur=cur->next;
    }
        return rev(head1);
    }
    
};
   


// { Driver Code Starts.

int main()
{
    int T;
	cin>>T;

	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;

		for(int i=0;i<K;i++){
		    int data;
		    cin>>data;
			if(head==NULL)
			    head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}
        Solution ob;
        Node *result = ob.compute(head);
        print(result);
        cout<<endl;
    }
}
  // } Driver Code Ends