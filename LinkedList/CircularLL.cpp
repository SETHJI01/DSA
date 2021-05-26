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
void insertAtbegin(node* end,node** head,int key){
    node *temp = new node(key);
    end->next = temp;
    temp->next = (*head);
    (*head) = temp;
}
void insertAtend(node** end,node* head,int key){
    node *temp = new node(key);
    (*end)->next = temp;
    temp->next = head;
    (*end) = temp;
}
void printCLL(node* head){
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
void delHeadgfg(node* head){
    if((*head)->next==(*head)){
        delete (*head);
        (*head) = NULL;
    }
    else{
        head->data = head->next->data;
        node *temp = head->next;
        head->next = temp->next;
        delete temp;
    }
}
void delHead(node** head,node* end){
    if((*head)->next==(*head)){
        delete (*head);
        (*head) = NULL;
    }
    else{
        node *temp = (*head);
        (*head) = (*head)->next;
        end->next = (*head);
        delete temp;
    }
}
void deletekth(node* head,int k){
    int i = 1;
    while (i < k-1){
        i++;
        head = head->next;
    }
    node *temp = head->next;
    head->next = temp->next;
    delete temp;
}
int main(){
    int n,val;
    cin >> n;
    node *head=NULL,*end=NULL;
    for (int i = 0; i < n; i++){
        cin >> val;
        node *temp = new node(val);
        if(head==NULL){
            head = temp;
            end = temp;
        }
        else{
            end->next = temp;
            end = temp;
        }
    }
    node *curr = end;
    if (head != NULL)
        curr->next = head;
    printCLL(head);
    insertAtbegin(end, &head, 10);
    printCLL(head);
    insertAtend(&end, head, 20);
    printCLL(head);
    deletekth(head, 1);
    // delHead(&head, end);
    printCLL(head);
}