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
void inorder(Node* node,unordered_map<int,int>&m){
    if(node==NULL)
        return;
    inorder(node->left,m);
    m[node->data] = 1;
    inorder(node->right, m);
}
bool isPair(Node *root,int sum, unordered_set<int> s){
    if(root==NULL)
        return false;
    if(isPair(root->left,sum,s)==true)
        return true;
    if(s.find(sum-root->data)!=s.end())
        return true;
    else
        s.insert(root->data);
    return isPair(root->right, sum, s);
}
int main()
{
    Node *root = new Node(10);
    root->left = new Node(8);
    root->left->right = new Node(9);
    root->right = new Node(20);
    root->right->left = new Node(11);
    root->right->right = new Node(30);
    root->right->right->left = new Node(25);
    unordered_map<int, int> m;
    inorder(root, m);
    int sum = 49, first = 0,second=0;
    for (auto x : m){
        if(m[x.first]==1&&m[sum-x.first]==1&&x.first!=0&&x.first!=sum){
            first = x.first;
            second = sum - x.first;
            break;
        }
    }
    if(first!=0)
        cout << first << " " << second;
    else
        cout << "No pair available " << endl;
}