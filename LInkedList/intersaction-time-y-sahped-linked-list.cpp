#include<bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

int intersectPoint(struct Node* head1, struct Node* head2);

Node* inputList(int size)
{
    if(size==0) return NULL;
    
    int val;
    cin>> val;
    
    Node *head = new Node(val);
    Node *tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>>val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

/* Driver program to test above function*/
int main()
{
    int T,n1,n2,n3;

    cin>>T;
    while(T--)
    {
        cin>>n1>>n2>>n3;
        
        Node* head1 = inputList(n1);
        Node* head2 = inputList(n2);
        Node* common = inputList(n3);
        
        Node* temp = head1;
        while(temp!=NULL && temp->next != NULL)
            temp = temp->next;
        if(temp!=NULL) temp->next = common;
        
        temp = head2;
        while(temp!=NULL && temp->next != NULL)
            temp = temp->next;
        if(temp!=NULL) temp->next = common;
        
        cout << intersectPoint(head1, head2) << endl;
    }
    return 0;
}

// } Driver Code Ends


/* Linked List Node
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */

//Function to find intersection point in Y shaped Linked Lists.
int intersectPoint(Node* head1, Node* head2)
{
    // Your Code Here
    Node* cur1=head1,*cur2=head2;
    int l1=0,l2=0;
    while(cur1!=NULL){
        l1++;
        cur1=cur1->next;
    }
     while(cur2!=NULL){
        l2++;
        cur2=cur2->next;
    }
    cur1=head1;
    cur2=head2;
    int k=abs(l1-l2);
    if(l1>l2){
        for(int i=0;i<k;i++){
            cur1=cur1->next;
        }
    }
    else{
        for(int i=0;i<k;i++){
            cur2=cur2->next;
        }
    }
    while(cur1!=NULL&&cur2!=NULL){
        if(cur1==cur2)
        {
            return cur1->data;
        }
        cur1=cur1->next;
        cur2=cur2->next;
    }
    return -1;
    }
    
    
    

