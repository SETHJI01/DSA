//maintaining a gap of n-1 nodes
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
    node *second = head, *first = head;
    while(n--){
        if(first==NULL&&n!=0)
            return NULL;
        first = first->next;
    }
    while(first!=NULL){
        first = first->next;
        second = second->next;
    }
    return second->data;
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