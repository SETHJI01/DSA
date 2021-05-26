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
void insertsorted(node** head,int key){
    node *temp = new node(key);
    if ((*head)->data > key){
        temp->next = (*head);
        (*head) = temp;
    }
    else{
        node *curr=(*head),*prev;
        while(curr!=NULL&&curr->data<key){
            prev = curr;
            curr = curr->next;
        }
        prev->next = temp;
        temp->next = curr;
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
    int key;
    cout << "Enter key : ";
    cin >> key;
    insertsorted(&head, key);
    printll(head);
}