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
void iterative_print(node* head){
    node *curr=head;
    while(curr!=NULL){
        if(curr->next!=NULL){
            cout<<curr->data<<"->";
        }
        else{
            cout<<curr->data;
        }
        curr=curr->next;
    }
}
node* insertAtBegin(node* head,int key){
    node* temp=new node(key);
    temp->next=head;
    head=temp;
    return head;
}
void insertAtEnd(node** head,int key){
    node* curr=(*head);
    while(curr->next!=NULL){
        curr=curr->next;
    }
    node* temp=new node(key);
    curr->next=temp;
}
void insertAtEnd2(node** end,int key){
    node* temp=new node(key);
    (*end)->next=temp;
    (*end)=temp;
}
void delFirstNode(node** head){
    node* temp= (*head);
    (*head)=(*head)->next;
    delete temp;
}
void delLastNode(node* head){
    node* curr=head;
    if(curr->next==NULL){
        delete curr;
    }
    while(curr->next->next!=NULL){
        curr=curr->next;
    }
    node* temp=curr->next;
    curr->next=NULL;
    delete temp;
}
node* insertAtPosition(node* head,int p,int key){
    if(p==1){
        node* temp=new node(key);
        temp->next=head;
        head=temp;
    }
    else{
        int c=0;
        node* curr=head;
        while(c<p-1){
            c++;
            curr=curr->next;
        }
        node* temp=curr->next;
        node* temp1=new node(key);
        curr->next=temp1;
        temp1->next=temp;
    }
    return head;
}
    //if in any function call we alter the head there will be no change in the main head as a copy is created while passing
void recursive_print(node* head){
    if(head==NULL)
        return;
    else if(head->next==NULL){
        cout<<head->data;
        recursive_print(head->next);
    }
    else{
        cout<<head->data<<"->";
        recursive_print(head->next);
    }
}
bool itr_search(node *head,int key){
    while(head!=NULL){
        if(head->data==key)
            return true;
        else
            head = head->next;
    }
    return false;
}
bool recur_search(node* head,int key){
    if(head==NULL)
        return false;
    if (head->data == key)
        return true;
    else
        return recur_search(head->next, key);
}
int main(){
    int n,val;
    cin>>n;
    node *head=NULL;
    node *end=NULL;
    for(int i=0;i<n;i++){
        cin>>val;
        if(head==NULL){
            head=new node(val);
            end=head;
        }
        else{
            node* temp=new node(val);
            end->next=temp;
            end=temp;
        }
    }

    iterative_print(head);
    cout<<endl;
    cout << "Enter the element : ";
    cin >> val;
    if (recur_search(head,val))//itr_search(head, val))
        cout<<"Element is present : "<<endl;
    else
        cout << "element not present " << endl;
    // int pos;
    // cout<<"Enter the value and the position : ";
    // cin>>val>>pos;
    // head=insertAtPosition(head,pos,val);
    // cout<<"After Insertion : ";
    // iterative_print(head);
    // cout<<endl;
    // cout<<"Before deleting the last element : ";
    // iterative_print(head);
    // cout<<endl;
    // delLastNode(head);
    // cout<<"after deleting the last element : ";
    // iterative_print(head);
    // cout<<endl;

    // cout<<"Enter the element you want to insert at the beginning of the LL : ";
    // cin>>val;
    // head=insertAtBegin(head,val);
    // recursive_print(head);
    // cout<<endl;
    // cout<<"Enter the element you want to insert at the end of the LL using start pointer : ";
    // cin>>val;
    // insertAtEnd(&head,val);
    // iterative_print(head);
    // cout<<endl;
    // //at above inserted at the end but not changed the end so this new fuction overwrite the above operation of insertion at end;
    // cout<<"Enter the element you want to insert at the end of the LL using end pointer : ";
    // cin>>val;
    // insertAtEnd2(&end,val);
    // iterative_print(head);
    // cout<<endl;
}
