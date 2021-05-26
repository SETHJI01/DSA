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
bool findPath(Node* root,int val,vector<Node*> &v){
    if(root==NULL)
        return false;
    v.push_back(root);
    if(root->data==val)
        return true;
    if (findPath(root->left, val, v) || findPath(root->right, val, v)){
        return true;
    }
    v.pop_back();
    return false;
}
int main(){
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    vector<Node *> p1;
    vector<Node*> p2;
    int n1 = 4, n2 = 5;
    findPath(root, n1, p1);
    findPath(root, n2, p2);
    cout << p1.size() << " " << p2.size() << endl;
    int i = 0;
    while(p1[i+1]==p2[i+1])
        i++;
    cout << p1[i]->data << endl;
    return 0;
}