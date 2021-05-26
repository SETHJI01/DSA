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
    if(head==NULL)
        cout << NULL << endl;
    while (head != NULL)
    {
        if(head->next==NULL)
            cout << head->data << endl;
        else 
            cout << head->data << "->";
        head = head->next;
    }
}
void reverseLL(node** head){
    node *curr=NULL, *prev=NULL, *nex=(*head);
    while(nex!=NULL){
        nex = nex->next;
        if (curr ==NULL)
            curr = (*head);
        curr->next = prev;
        prev = curr;
        curr = nex;
    }
    (*head) = prev;
}
node* middle(node* head){
    if(head==NULL)
        return NULL;
    node *slow = head, *fast = head;
    while(fast!=NULL&&fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
bool palindrome(node* head){
    if(head==NULL)
        return false;
    node *mid = middle(head);
    reverseLL(&(mid->next));
    node *curr = mid->next;
    while(curr!=NULL){
        if(head->data==curr->data){
            head = head->next;
            curr = curr->next;
        }
        else
            return false;
    }
    return true;
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
    if(palindrome(head))
        cout << "The Linked List is Palindrome " << endl;
    else
        cout << "The Linked List is Not Palindrome " << endl;
}