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
int NthNodeFromLast(node* head,int n){
    if(head==NULL)
        return NULL;
    int count = 0;
    node *temp = head;
    while(temp!=NULL){
        count++;
        temp = temp->next;
    }
    if(n>count)
        return NULL;
    for (int i = 0; i < count - n; i++)
    {
        head = head->next;
    }
    return head->data;
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
    cout << "The nth element from end is : " << NthNodeFromLast(head,2);
}