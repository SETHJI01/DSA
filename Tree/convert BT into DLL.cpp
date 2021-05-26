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

Node *pre = NULL;

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

Node *BTToDLL(Node *root){
    if(root==NULL)
        return root;
    Node *head = BTToDLL(root->left);
    if(pre==NULL)
        head = root;
    else{
        root->left = pre;
        pre->right = root;
    }
    pre = root;
    BTToDLL(root->right);
    return head;
}
int main(){
    Node *root = createTree();
    inorder(root);
    cout << endl;
    Node *head = BTToDLL(root);
    Node *temp = head;
    while(temp!=NULL){
        cout << temp->data<<" ";
        temp = temp->right;
    }
}