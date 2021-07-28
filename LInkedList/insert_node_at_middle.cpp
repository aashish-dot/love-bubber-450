#include<bits/stdc++.h>
using namespace std;
struct Node {
	int data;
	Node *next;
	Node(int x){
		data=x;
		next=NULL;
	}
};
Node* insertInMiddle(Node* head, int x)
{
	// Cpde here
	if(head==NULL){
	    return head;
	}
	Node* temp=new Node(x);
	//Node* prev=head;
	Node *slow=head,*fast=head->next;
	while(fast!=NULL&&fast->next!=NULL){
	    fast=fast->next->next;
	    slow=slow->next;
	}
	temp->next=slow->next;
	slow->next=temp;
	return head;
}