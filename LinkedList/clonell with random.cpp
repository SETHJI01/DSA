#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node *next;
    node *random;
    node(int x){
        data=x;
        next=NULL;
        random = NULL;
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
node* createclone(node* head){
    node *curr = head;
    node *new_head;
    map<node *, node *> m;
    while (curr != NULL){
        m[curr] = new node(curr->data);
        if(curr==head){
            new_head = m[curr];
        }
    }
    curr = head;
    node* new_curr = new_head;
    while (curr != NULL){
        new_curr->next = m[curr->next];
        new_curr->random = m[curr->random];
        new_curr = new_curr->next;
        curr = curr->next;
    }
    return new_head;
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
    node* new_node=createclone(head);
    printll(new_node);
}