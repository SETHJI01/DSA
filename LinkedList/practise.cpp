// { Driver Code Starts
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

Node* mergeKLists(Node* arr[], int K);

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

   		Node *res = mergeKLists(arr,N);
		printList(res);

   }

	return 0;
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
Node* merge(Node* head,Node* nex){
    Node* h=NULL,*curr=NULL;
    while(head&&nex){
        if(head->data<nex->data){
            if(h==NULL){
                h = head;
                curr = head;
            }
            else{
                curr->next=head;
                curr=head;
            }
            head = head->next;
        }
        else{
            if(h==NULL){
                h = nex;
                curr = nex;
            }
            else{
                curr->next=nex;
                curr=nex;
            }
            nex = nex->next;
        }
    }
    while(head){
        curr->next=head;
        curr=head;
        head=head->next;
    }
    while(nex){
        curr->next=nex;
        curr=nex;
        nex=nex->next;
    }
    return h;
}
//Function to merge K sorted linked list.
Node * mergeKLists(Node *arr[], int k){
       // Your code here
       if(k<1)
       return arr[0];
    Node* head=merge(arr[0],arr[1]);
    for(int i=2;i<k;i++){
        head=merge(head,arr[i]);
    }
    return head;
}

