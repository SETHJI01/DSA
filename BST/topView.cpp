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
void solve(Node* root,map<int,int> &m){
    queue<pair<Node *, int>> q;
    q.push({root, 0});
    while(!q.empty()){
        auto p = q.front();
        Node *curr = p.first;
        int hd = p.second;
        m[hd] = curr->data;
        q.pop();
        if(curr->left)
            q.push({curr->left, hd - 1});
        if(curr->right)
            q.push({curr->right, hd + 1});
    }
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
    solve(root, m);
    for(auto x:m){
        cout << x.second << " ";
    }
}