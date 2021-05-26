#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node *next;
    node(int x){
        data = x;
    }
};
void printll(node *head)
{
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

// node* mergeLL(node* h1,node* h2){
//     if(h1==NULL)
//         return h2;
//     if(h2==NULL)
//         return h1;
//     node *nh=NULL,*curr=NULL;
//     while (h1 && h2){
//         if (h1->data<h2->data){
//             if(nh==NULL){
//                 nh = h1;
//                 curr = h1;
//             }
//             else{
//                 curr->next = h1;
//                 curr = h1;
//             }
//             h1 = h1->next;
//         }
//         else{
//             if(nh==NULL){
//                 nh = h2;
//                 curr = h2;
//             }
//             else{
//                 curr->next = h2;
//                 curr = h2;
//             }
//             h2 = h2->next;
//         }
//     }
//     while(h1){
//         curr->next = h1;
//         curr = h1;
//         h1 = h1->next;
//     }
//     while(h2){
//         curr->next = h2;
//         curr = h2;
//         h2 = h2->next;
//     }
//     return nh;
// }
int main(){
    node *h1 = NULL, *h2 = NULL,*curr=NULL,*curr1=NULL;
    int n,val;
    cout << "For h1 : ";
    cin >> n;
    while(n--){
        cin >> val;
        node *temp = new node(val);
        if(h1==NULL){
            h1 = curr = temp;
        }
        else{
            curr->next = temp;
            curr = temp;
        }
    }
    cout << "For h2 : ";
    cin >> n;
    while(n--){
        cin >> val;
        node *temp = new node(val);
        if(h2==NULL){
            h2 = curr1 = temp;
        }
        else{
            curr1->next = temp;
            curr1 = temp;
        }
    }
    printll(h1);
    printll(h2);
    node *nh = merge(h1, h2);
    printll(nh);
}
