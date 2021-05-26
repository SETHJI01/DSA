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
void remove_dup(node* head){
    if(head==NULL)
        return;
    node* curr = head->next;
    while (curr != NULL){
        if(head->data==curr->data){
            node *temp = curr;
            head->next = curr->next;
            curr = curr->next;
            delete temp;
            continue;
        }
        head = head->next;
        curr = curr->next;
    }
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
    remove_dup(head);
    printll(head);
}