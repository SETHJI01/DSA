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
    int c1 = 0, c2 = 0;
    node *s = h1;
    while(s!=NULL){
        c1++;
        s = s->next;
    }
    s = h2;
    while (s != NULL){
        c2++;
        s = s->next;
    }
    if(c1>c2){
        int count = 0;
        while (count<c1-c2){
            if(h1==NULL)
                return -1;
            h1 = h1->next;
            count++;
        }
        while(h1!=NULL&&h2!=NULL){
            if(h1==h2){
                return h1->data;
            }
            h1 = h1->next;
            h2 = h2->next;
        }
    }
    else{
        int count = 0;
        while (count<c2-c1){
            if(h2==NULL)
                return -1;
            h2 = h2->next;
            count++;
        }
        while(h1!=NULL&&h2!=NULL){
            if(h1==h2){
                return h1->data;
            }
            h1 = h1->next;
            h2 = h2->next;
        }
    }
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