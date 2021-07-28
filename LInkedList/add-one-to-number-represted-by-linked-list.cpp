//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data; 
        node = node->next; 
    }  
    cout<<"\n";
} 


 // } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    Node *rev(Node* head){
        if(head==NULL||head->next==NULL)
            return head;
        Node* cur=head,*pre=NULL;
        while(cur!=NULL){
            Node*next=cur->next;
            cur->next=pre;
            pre=cur;
            cur=next;
        }
        return pre;
    }
    Node* addOne(Node *head) 
    {
        // Your Code here
        // return head of list after adding one
        if(head==NULL){
            return head;
        }
        if(head->next==NULL){
            int k=(head->data+1);
            head->data=k%10;
            if(k>9){
                int carry=k/10;
                Node * temp=new Node(carry);
                temp->next=head;
                return temp;
            }
            return head;
        }
    
        
        Node* h=rev(head);
        Node* cur=h->next;
        int carry=0;
        int k=h->data+1;
     
        
            h->data=k%10;
            carry=k/10;
        
        while(cur->next!=NULL){
            int sum=cur->data+carry;
           
                cur->data=sum%10;
                carry=sum/10;
            
            cur=cur->next;
        }
        int sum=cur->data+carry;
            
                cur->data=sum%10;
                carry=sum/10;
    
        if(carry>0){
            Node* temp=new Node(carry);
            cur->next=temp;
        }
        return rev(h);
    }
};

// { Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 
  // } Driver Code Ends