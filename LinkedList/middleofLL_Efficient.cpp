//This is the efficient approach to Find the middle of the linked list
//based on slow and fast moving pointers
#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node *next;
    node(int x){
        data=x;
        next=NULL;
    }
};
void printll(node* head){
    while(head!=NULL){
        if(head->next==NULL)
            cout << head->data << endl;
        else 
            cout << head->data << "->";
        head = head->next;
    }
}
int middle(node* head){
    if(head==NULL)
        return NULL;
    node *slow = head, *fast = head;
    while(fast!=NULL&&fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow->data;
}
int main(){
    int n,val,t;
    cin >> n;
    t = n;
    node *head = NULL, *curr;
    while (t--){
        cin >> val;
        node *temp = new node(val);
        if(head==NULL){
            head = temp;
            curr = temp;
        }
        else{
            curr->next = temp;
            curr=temp;
        }
    }
    printll(head);
    cout << "The middle element is : " << middle(head);
}