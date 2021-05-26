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
int countNode(Node* root){
    if(root==NULL)
        return 0;
    int lh = 0, rh = 0;
    Node *temp = root;
    while (temp != NULL){
        lh++;
        temp = temp->left;
    }
    temp = root;
    while(temp!=NULL){
        rh++;
        temp = temp->right;
    }
    if(lh==rh){
        return pow(2, lh) - 1;
    }
    else
        return 1 + countNode(root->left) + countNode(root->right);
}
int main(){
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->left->left->left = new Node(8);
    root->left->left->right = new Node(9);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(11);
    root->right->left->left = new Node(12);
    cout << countNode(root)<<endl;
}