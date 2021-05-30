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
//preorder is not sufficient //so we use level order 
void solve(Node* root,map<int,vector<int> > &m){
    queue<pair<Node *, int>> q;
    q.push({root, 0});
    while(!q.empty()){
        auto p = q.front();
        Node *curr = p.first;
        int hd = p.second;
        m[hd].push_back(curr->data);
        q.pop();
        if(curr->left)
            q.push({curr->left, hd - 1});
        if(curr->right)
            q.push({curr->right, hd + 1});
    }
}
int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right = new Node(3);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->right->left = new Node(8);
    root->right->right->left->left = new Node(9);

    map<int, vector<int>> m;
    solve(root, m);
    for(auto x:m){
        for (int i = 0; i < x.second.size();i++)
            cout << x.second[i] << " ";
        cout << endl;
    }
}