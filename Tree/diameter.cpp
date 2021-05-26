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

Node* createTree(){
    cout << "Enter the data of the node : ";
    int x,ch;
    cin >> x;
    Node *temp = new Node(x);
    cout << "if "<<x<<" has left child enter 1 or 0 if not : ";
    cin >> ch;
    if(ch==1){
        temp->left = createTree();
    }
    cout << "if "<<x<<" has right child enter 1 or 0 if not : ";
    cin >> ch;
    if(ch==1){
        temp->right = createTree();
    }
    return temp;
}
void inorder(Node* node){
    if(node==NULL)
        return;
    inorder(node->left);
    cout << node->data << " ";
    inorder(node->right);
}
int dia(Node* node,int &maxi){
    if(node==NULL)
        return 0;
    int h1 = dia(node->left, maxi), h2 = dia(node->right, maxi);
    if(h1+h2+1>maxi)
        maxi = h1 + h2 + 1;
    return max(h1, h2) + 1;
}
int main(){
    Node *root = createTree();
    int maxi = 0;
    int h = dia(root, maxi);
    cout << "Diameter is = " << maxi<< endl;
    return 0;
}