#include<bits/stdc++.h>
using namespace std;
typedef struct Node{
    int data;
    Node *left, *right;
    Node(int x){
        data = x;
        left = right = NULL;
    }
}Node;
Node* check(Node* root,int n1,int n2){
    if(root==NULL)
        return NULL;
    if(root->data==n1||root->data==n2){
        return root;
    }
    Node *p1=check(root->left, n1, n2);
    Node *p2 = check(root->right, n1, n2);
    if (p1 != NULL && p2!= NULL)
        return root;
    if(p1)
        return p1;
    return p2;
}
int main(){
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    Node *ans = check(root, 4, 5);
    cout << ans->data << endl;
}