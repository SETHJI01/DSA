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

//1st method
//Naive Approach
int distance(node* start,node* end){
    int count = 0;
    while(start!=end){
        count++;
        start = start->next;
    }
    return count+1;
}
bool Naive(node* head){
    node *first = head, *last = head;
    int prev_d = -1, curr_d = 0;
    while(curr_d>prev_d&&last!=NULL){
        prev_d = curr_d;
        curr_d = distance(first, last);
        last = last->next;
    }
    if(last==NULL)
        return false;
    else
        return true;
}
//2nd Method
//Visited approach need a extra bool variable visited;


//3rd method
//dummy node method we traverse through linked list while making the next of curr node to temp
//if we reach a node whose next is already temp then return true;
bool isLoop(node *head)
{   node* temp=new node(0);
    node *curr=head;
    while (curr != NULL) {  
        if (curr->next==NULL)
            return false;
        if(curr->next==temp)
            return true;
        node *curr_next=curr->next;
        curr->next=temp;
        curr=curr_next;
    } 
    return false; 
}

//4th method 
//using hashing 
bool isLoop2(node* head){
    unordered_set<node *> set;
    for (node *i = head; i != NULL;i=i->next){
        if(set.find(i)!=set.end())
            return true;
    }
    return false;
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
    if(Naive(head))
        cout << "The linked list contains a loop " << endl;
    else
        cout << "The linked list doesn't contains a loop " << endl;
}