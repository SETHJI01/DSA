#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node *prev;
    Node *next;
    Node(int x){
        data = x;
        prev = NULL;
        next = NULL;
    }
};
void print(Node* head){
    while(head!=NULL){
        if(head->next==NULL)
        cout << head->data;
        else
        cout << head->data<<"->";
        head = head->next;
    }
    cout << endl;
}
void delAtEnd(Node** end){
    cout << "Element deleted !!" << endl;
    Node *temp = (*end);
    (*end) = (*end)->prev;
    (*end)->next = NULL;
    delete temp;
}
void revprint(Node *end){
    while(end!=NULL){
        cout << end->data << "->";
        end = end->prev;
    }
    cout << endl;
}
void insertAtBegin(Node** head,int key){
    Node *temp = new Node(key);
    temp->next = (*head);
    (*head) = temp;
}
void reverseDLL(Node** head,Node** end){
    Node *previ = NULL, *curr = (*head);
    (*end) = (*head);
    while (curr != NULL){
        previ = curr->prev;
        curr->prev = curr->next;
        curr->next = previ;
        curr = curr->prev;
    }
    (*head)=previ->prev;
}
void delhead(Node** head){
    Node *temp = (*head);
    (*head) = (*head)->next;
    (*head)->prev = NULL;
    delete temp;
}
void dellast(Node** end){
    Node *temp = (*end);
    (*end) = (*end)->prev;
    (*end)->next = NULL;
    delete temp;
}
int main(){
    int n,val;
    cin >> n;
    Node *head, *end;
    for (int i = 0; i < n; i++){
        cin >> val;
        Node *temp = new Node(val);
        if (i == 0){
            head = temp;
            end = temp;
        }
        else{
            end->next = temp;
            temp->prev = end;
            end = temp;
        }
    }
    print(head);
    dellast(&end);
    // delhead(&head);
    // reverseDLL(&head, &end);
    print(head);
    // print(head);
    // // cout << "Enter the Element to insert at beginning : ";
    // // cin >> val;
    // // insertAtBegin(&head, val);
    // delAtEnd(&end);
    // print(head);
    // cout << "The DLL is : ";
    // print(head);
    // cout << "the reverse DLL is :";
    // revprint(end);
}