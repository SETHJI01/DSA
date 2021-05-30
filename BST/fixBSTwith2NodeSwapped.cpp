#include<bits/stdc++.h>
using namespace std;
typedef struct Node{
    int data;
    Node *right, *left;
    Node(int key){
        data = key;
        right = NULL;
        left = NULL;
    }
} Node;
void checkBST3(Node* root,bool &check,int &ans){
    if(root==NULL){
        return;
    }
    checkBST3(root->left, check,ans);
    if(root->data<ans){
        check = false;
        return;
    }
    ans = root->data;
    checkBST3(root->right, check, ans);
}
void inorder(Node* node,Node* & first,Node* &second,Node* &prev){
    if(node==NULL)
        return;
    inorder(node->left,first,second,prev);
    if(prev!=NULL&&prev->data>node->data){
        if(first==NULL)
            first = prev;
        second = node;
    }
    prev = node;
    inorder(node->right,first,second, prev);
}
void solve(Node* root){
    Node *prev = NULL,*first=NULL,*second=NULL;
    inorder(root, first,second,prev);
    cout << first->data << " " << second->data << endl;
    int temp = first->data;
    first->data = second->data;
    second->data = temp;
}
int main(){
    Node *root = new Node(18);
    root->left = new Node(60);
    root->right = new Node(70);
    root->right->left = new Node(8);
    root->right->right = new Node(80);
    solve(root);
    // bool check = true;
    // int ans = -1;
    // checkBST3(root, check, ans);
    // cout << check << endl;
}