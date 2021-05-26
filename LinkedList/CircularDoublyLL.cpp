#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node *next;
    node *prev;
    node(int x){
        data=x;
        next=NULL;
        prev = NULL;
    }
};
void printCDLL(node* head){
    if(head==NULL){
        cout << NULL;
        return;
    }
    node *curr = head;
    do{
        if(curr->next==head)
            cout << curr->data;
        else
            cout << curr->data << "->";
        curr = curr->next;
    } while (curr != head);
    cout << endl;
}

void insertAtHead(node **head,int key){
    node *temp = new node(key);
    node *temp2 = (*head)->prev;
    temp->next = (*head);
    (*head)->prev = temp;
    (*head) = temp;
    (*head)->prev = temp2;
    temp2->next = (*head);
}
int main(){
    int n,val;
    cin >> n;
    node *head = NULL, *end = NULL;
    while (n--)
    {
        cin >> val;
        node *temp = new node(val);
        if(head==NULL){
            head = temp;
            end = temp;
        }
        else{
            end->next = temp;
            temp->prev = end;
            end = temp;
        }
    }
    end->next = head;
    head->prev = end;
    printCDLL(head);
    insertAtHead(&head, 10);
    printCDLL(head);
}