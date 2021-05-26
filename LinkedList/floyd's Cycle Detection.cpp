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
bool floyd(node* head){
    node *slow = head, *fast = head;
    while (fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow==fast){
            cout << slow->data << endl;
            break;
        }
    }
    if(slow!=fast){
        return false;
    }
    //for removing the loop from ll;
    node *p = head;
    while(p->next!=fast->next){
        p = p->next;
        fast = fast->next;
        cout << p->data << " " << fast->data << endl;
    }
    fast->next = NULL;
    cout << p->next->data << " is the starting point of the loop \n";
    return true;

    // //for finding the point from where the loop started
    // node *p = head;
    // while(p!=fast){
    //     p = p->next;
    //     fast = fast->next;
    // }
    // cout << p->data << " is the starting point of the loop \n";
    // return true;
}
int main()
{
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
    curr->next=head->next->next;
    if(floyd(head)){
        cout << "The linked list contains a loop " << endl;
        cout << "the loop is automatically removed \n";
        printll(head);
    }
    else{
        cout << "The linked list doesn't contains a loop " << endl;
        printll(head);
    }
    return 0;
}