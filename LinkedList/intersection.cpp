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
int intersection(node* h1,node* h2){
    unordered_set<node *> hs;
    while(h1!=NULL){
        hs.insert(h1);
        h1 = h1->next;
    }
    while(h2!=NULL){
        if(hs.find(h2)!=hs.end()){
            return h2->data;
        }
        h2 = h2->next;
    }
    if(h2==NULL)
        return -1;
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
    node *h2=new node(99);
    h2->next = head->next->next;
    printll(head);
    printll(h2);
    int inte = intersection(head, h2);
    cout << inte<< endl;
}