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
void solve(Node* root,int vlevel,map<int,int> &m){
    if(root==NULL)
        return;
    solve(root->left, vlevel - 1, m);
    if(m[vlevel])
        m[vlevel] += root->data;
    else
        m[vlevel] = root->data;
    solve(root->right, vlevel + 1, m);
}
int main()
{
    Node *root = new Node(10);
    root->left = new Node(15);
    root->left->left = new Node(35);
    root->left->left->left = new Node(40);
    root->left->right = new Node(20);
    root->left->right->right = new Node(25);
    root->left->right->right->right = new Node(80);
    root->right = new Node(25);
    map<int, int> m;
    solve(root, 0, m);
    for(auto x:m){
        cout << x.second << " ";
    }
}