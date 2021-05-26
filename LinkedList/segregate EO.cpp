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
node* segregate(node* head){
    node *eS = NULL,*eE = NULL,*oE = NULL, *oS = NULL,*start=head;
    while(head!=NULL){
        if(head->data%2==0){
            if(eS==NULL){
                eS = head;
                eE = eS;
            }
            else{
                eE->next = head;
                eE = head;
            }
        }
        else{
            if(oS==NULL){
                oS = head;
                oE = head;
            }
            else{
                oE->next = head;
                oE = head;
            }
        }
        head = head->next;
    }
    if(eS==NULL||oS==NULL)
        return start;
    else{
        eE->next = oS;
        oE->next = NULL;
        return eS;
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
    cout << "After Segregation : " << endl;
    head=segregate(head);
    printll(head);
}