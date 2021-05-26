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
void del(node* temp){
    node *temp1 = temp->next;
    if(temp1!=NULL){
        temp->data = temp1->data;
        temp->next = temp1->next;
    }
    else
        temp = NULL;
    delete temp1;
}
int main()
{
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
    cout << curr->data << endl;
    printll(head);
    del(curr);
    printll(head);
    return 0;
}