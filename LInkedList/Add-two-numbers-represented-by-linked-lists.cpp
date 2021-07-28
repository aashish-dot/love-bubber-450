// driver

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


 // } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
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
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // code here
        first=rev(first);
        Node* head=new Node(0);
        second=rev(second);
        Node* cur1=first;
        Node* cur2=second;
        Node* temp=head;
        int sum=0,carry=0;
        while(cur1!=NULL&&cur2!=NULL){
            sum=cur1->data+cur2->data+carry;
            temp->next=new Node(sum%10);
            carry=sum/10;
            temp=temp->next;
            cur1=cur1->next;
            cur2=cur2->next;
        }
       
        if(cur1==NULL){
            while(cur2!=NULL){
                 sum=cur2->data+carry;
                temp->next=new Node(sum%10);
                carry=sum/10;
            temp=temp->next;
            cur2=cur2->next;
            }
        }
         if(cur2==NULL){
            while(cur1!=NULL){
                 sum=cur1->data+carry;
                temp->next=new Node(sum%10);
                carry=sum/10;
            temp=temp->next;
            cur1=cur1->next;
            }
        }
     if(carry>0){
                temp->next=new Node(carry);
            }
            return rev(head->next);
        }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}
  // } Driver Code Ends