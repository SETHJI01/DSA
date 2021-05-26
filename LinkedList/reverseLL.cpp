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
void reverseLL(node** head){
    node *curr=NULL, *prev=NULL, *nex=(*head);
    while(nex!=NULL){
        nex = nex->next;
        if (curr ==NULL)
            curr = (*head);
        curr->next = prev;
        prev = curr;
        curr = nex;
    }
    (*head) = prev;
}
node *recursiveReverseLLmethod1(node *head){
    if(head==NULL||head->next==NULL)
        return head;
    node* ret_head=recursiveReverseLLmethod1(head->next);
    node *ret_tail = head->next;
    ret_tail->next = head;
    head->next = NULL;
    return ret_head;
}

node* recursiveReverseLLmethod2(node*prev,node* curr,node* nex){
    if(nex==NULL){
        return prev;
    }
    if(curr==NULL)
        curr = nex;
    nex = nex->next;
    curr->next = prev;
    prev = curr;
    curr = nex;
    return recursiveReverseLLmethod2(prev, curr, nex);
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
    head=recursiveReverseLLmethod1(head);
    printll(head);
}