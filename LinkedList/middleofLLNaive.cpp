//in this i will first find the number of element in ll
//then run a loop for n/2 time then print the data;
//corner case if head==NULL
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
int middle(node* head,int n){
    if(head==NULL)
        return NULL;
    for (int i = 0; i < n / 2; i++){
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
    cout << "The middle element is : " << middle(head,n);
}