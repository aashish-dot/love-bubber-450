#include <bits/stdc++.h>

using namespace std;
/* Link list Node */
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node *start = NULL;


 // } Driver Code Ends
/*
 
  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        
        // Add code here
        if(head==NULL)
            return head;
        Node* zero=new Node(0);
        Node* one=new Node(0);
        Node* two=new Node(0);
        Node* temp=zero,*temp1=one,*temp2=two;
        Node* cur=head;
        while(cur!=NULL){
            if(cur->data==0){
                zero->next=new Node(0);
                zero=zero->next;
            }
            else if(cur->data==1){
                one->next=new Node(1);
                one=one->next;
            }
            else{
                two->next=new Node(2);
                two=two->next;
            }
            cur=cur->next;
        }
        Node* head1;
        if(temp->next!=NULL){
            head1=temp->next;
            if(temp1->next!=NULL){
                zero->next=temp1->next;
                if(temp2->next!=NULL){
                    one->next=temp2->next;
                }
                
            }
            else if(temp2->next!=NULL){
                zero->next=temp2->next;
            }
            
        }
        else if(temp1->next!=NULL){
            
                head1=temp1->next;
                if(temp2->next!=NULL){
                    one->next=temp->next;
                }
                
            }
        else{
            head1=temp2->next;
        }
        return head1;
    }
};


// { Driver Code Starts.

// Function to sort a linked list of 0s, 1s and 2s
void printList(struct Node *Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
void insert(int n1) {
    int n, value, i;
    // scanf("%d",&n);
    n = n1;
    struct Node *temp;
    for (i = 0; i < n; i++) {
        scanf("%d", &value);

        if (i == 0) {
            start = new Node(value);
            temp = start;
            continue;
        } else {
            temp->next = new Node(value);
            temp = temp->next;
            temp->next = NULL;
        }
    }
}

int main() {

    int n;

    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        insert(n);
        Solution ob;
        struct Node *newHead = ob.segregate(start);
        printList(newHead);
    }

    return 0;
}  // } Driver Code Ends