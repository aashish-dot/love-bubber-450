#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


 // } Driver Code Ends


/* Structure of the linked list node is as
struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/

/* Function to mergesort the linked list
   It should return head of the modified list  */
   Node *mergeTwoLists(Node *l1, Node *l2) {
            if(l1 == NULL) return l2;
            if(l2 == NULL) return l1;

            Node* head = NULL;    // head of the list to return

            // find first element (can use dummy node to put this part inside of the loop)
            if(l1->data < l2->data) {
                head = l1;
                l1 = l1->next;
            } else {
                head = l2;
                l2 = l2->next;
            }

            Node* p = head;     // pointer to form new list

            while(l1 && l2){
                if(l1->data < l2->data) {
                    p->next = l1;
                    l1 = l1->next;
                } else {
                    p->next = l2;
                    l2 = l2->next;
                }
                p = p->next;
            }

            // add the rest of the tail, done!
            if (l1) {
                p->next=l1;
            } else {
                p->next=l2;
            }

            return head;
        }
Node* mergeSort(Node* head) {
    // your code here
    if (head == NULL || head->next == NULL)
                return head;

            // find the middle place
            Node *p1 = head;
            Node *p2 = head->next;
            while(p2 && p2->next) {
                p1 = p1->next;
                p2 = p2->next->next;
            }
            p2 = p1->next;
            p1->next = NULL;

            return mergeTwoLists(mergeSort(head), mergeSort(p2)); 
}


// { Driver Code Starts.

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    long test;
    cin >> test;
    while (test--) {
        struct Node* a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            push(&a, tmp);
        }
        a = mergeSort(a);
        printList(a);
    }
    return 0;
}  // } Driver Code Ends