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
void reverseInGroup(node** head,int k){
    node *temp=(*head);
    node* uni_start=NULL,*prev_end=NULL;
    for (auto i = temp; i != NULL;){
        int t = k - 1;
        node *j = i, *nex=NULL,*start=i;
        while (i->next!= NULL&&t--){
            i = i->next;
        }
        nex = i->next;
        i->next = NULL;
        j=reverseLL(j);
        if(uni_start==NULL)
            uni_start = j;
        if (prev_end != NULL){
            prev_end->next = j;
            prev_end = start;
        }
        else
            prev_end = start;
        i = nex;
    }
    (*head) = uni_start;
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
    reverseInGroup(&head,2);
    printll(head);
}