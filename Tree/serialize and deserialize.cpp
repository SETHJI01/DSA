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
void inorder(Node* node){
    if(node==NULL)
        return;
    inorder(node->left);
    cout << node->data << " ";
    inorder(node->right);
}
void Serialize(Node* root,vector<int> &v){
    if(root==NULL){
        v.push_back(-1);
        return;
    }
    v.push_back(root->data);
    Serialize(root->left, v);
    Serialize(root->right, v);
}
Node *Deserialize(vector<int> v,int &i){
    if(i==v.size())
        return NULL;
    Node *temp;
    int val = v[i];
    i++;
    if (val == -1)
        return NULL;
    else
        temp = new Node(val);
    temp->left = Deserialize(v, i);
    temp->right = Deserialize(v, i);
    return temp;
}
int main(){
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    // cout << countNode(root)<<endl;
    vector<int> v;
    int i = 0;
    Serialize(root, v);
    for (i = 0; i < v.size();i++){
        cout << v[i] << " ";
    }
    cout << endl;
    i = 0;
    Node *temp = Deserialize(v, i);
    inorder(temp);
    return 0;
}