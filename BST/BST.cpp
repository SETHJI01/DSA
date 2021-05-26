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
Node* recur_insert(Node* root,int key){
    if(root==NULL){
        Node *temp = new Node(key);
        return temp;
    }
    if(key<root->data)
        root->left = recur_insert(root->left, key);
    else if(key>root->data)
        root->right = recur_insert(root->right, key);
    return root;
}
Node* getSuccessor(Node* root){
    root = root->right;
    while(root!=NULL&&root->left!=NULL)
        root = root->left;
    return root;
}
Node* deleteNode(Node* root,int key){
    if(root==NULL)
        return NULL;
    if(key<root->data)
        root->left = deleteNode(root->left, key);
    if(key>root->data)
        root->right = deleteNode(root->right, key);
    else{
        if(root->left==NULL){
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else if(root->right==NULL){
            Node *temp = root->left;
            delete root;
            return temp;
        }
        else{
            Node *temp = getSuccessor(root);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}
Node* iterative_insert(Node* root,int key){
    Node *parent = NULL, *current = root,*temp=new Node(key);
    while(root!=NULL){
        parent = root;
        if (key < root->data)
            root = root->left;
        else if(key>root->data)
            root = root->right;
        else
            return current;
    }
    if(parent==NULL)
        return temp;
    if(parent->data>key)
        parent->left = temp;
    else
        parent->right = temp;
    return current;
}
void inorder(Node* root){
    if(root==NULL)
        return;
    inorder(root->left);
    cout << root->data<<" ";
    inorder(root->right);
}
int main(){
    // int n;
    // cin >> n;
    // int arr[n];
    // for (int i = 0; i < n;i++){
    //     cin >> arr[i];
    // }
    // Node *root;
    // for (int i = 0; i < n;i++){
  cout << endl; //     root = iterative_insert(root, arr[i]);
    // }
    Node *root=new Node(10);
	root->left=new Node(5);
	root->right=new Node(15);
	root->right->left=new Node(12);
	root->right->right=new Node(18);
	int x=20;
    root = recur_insert(root, x);
    root = recur_insert(root, 1);
    root = recur_insert(root, 6);
    root = recur_insert(root, 13);
    inorder(root);
    cout << endl;
    root = deleteNode(root, 10);
    inorder(root);
    cout << endl;
}