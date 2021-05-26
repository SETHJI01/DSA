#include <bits/stdc++.h> 
using namespace std; 

struct Node 
{ 
    int data; 
    Node *next,*random; 
    Node(int x) 
    { 
        data = x; 
        next = random = NULL; 
    } 
}; 

void print(Node *start) 
{ 
    Node *ptr = start; 
    while (ptr) 
    { 
        cout << "Data = " << ptr->data << ", Random  = "<< ptr->random->data << endl; 
        ptr = ptr->next; 
    } 
}
Node* clone(Node* head){
    //first inserting copy nodes exact a position ahead to the current
    Node *curr = head,*next;
    while(curr!=NULL){
        next = curr->next;
        Node *temp = new Node(curr->data);
        curr->next = temp;
        temp->next = next;
    }
    //copying the links in new manner
    curr = head;
    while(curr!=NULL){
        curr->next->random = (curr->random != NULL) ? curr->random->next : NULL;
    }
    //segregating the nodes
    Node *original = head, *copy = head->next;
    curr = copy;
    while (original&&copy){
        original->next = original->next ? original->next->next : NULL;
        copy->next = copy->next ? copy->next->next : NULL;
        original = original->next;
        copy = copy->next;
    }
    return curr;
}
int main() 
{ 
	Node* head = new Node(10); 
    head->next = new Node(5); 
    head->next->next = new Node(20); 
    head->next->next->next = new Node(15); 
    head->next->next->next->next = new Node(20); 
    
    head->random = head->next->next;
    head->next->random=head->next->next->next;
    head->next->next->random=head;
    head->next->next->next->random=head->next->next;
    head->next->next->next->next->random=head->next->next->next;
    
    cout << "Original list : \n"; 
    print(head); 
  
    cout << "\nCloned list : \n"; 
    Node *cloned_list = clone(head); 
    print(cloned_list); 
  
    return 0; 
} 
