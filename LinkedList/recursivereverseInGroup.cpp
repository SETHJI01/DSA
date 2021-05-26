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
node* reverseLL(node* head){
    node *curr=NULL, *prev=NULL, *nex=head;
    while(nex!=NULL){
        nex = nex->next;
        if (curr ==NULL)
            curr = head;
        curr->next = prev;
        prev = curr;
        curr = nex;
    }
    return prev;
}
node* recursivereverseInGroup(node* head,int k){
    node *curr=head,*prev=NULL,*nex=NULL;
    int count=0;
    while(curr!=NULL&&count<k){
        nex=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nex;
        count++;
    }
    if(nex!=NULL){
        node *rest_head = recursivereverseInGroup(curr, k);
        head->next = rest_head;
    }
    return prev;
}
int main(){
    int n,val;
    cin >> n;
    node *head=NULL,*curr;
    while (n--){
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
    head=recursivereverseInGroup(head,3);
    printll(head);
}