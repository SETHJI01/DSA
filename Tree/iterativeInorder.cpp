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
void iterativeInorder(Node *root){
    stack<Node *> st;
    Node *temp = root;
    while (temp!=NULL||st.empty()==false){
        while(temp!=NULL){
            st.push(temp);
            temp = temp->left;
        }
        temp = st.top();
        st.pop();
        cout << temp->data << " ";
        temp = temp->right;
    }
}
void iterativePreorder(Node* root){
    Node *curr = root;
    stack<Node *> st;
    while(curr!=NULL || !st.empty()){
        while(curr!=NULL){
            cout << curr->data << " ";
            st.push(curr);
            curr = curr->left;
        }
        curr = st.top();
        st.pop();
        curr = curr->right;
    }
}
int main(){
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    // Node *root = new Node(1);
    // root->left        = new Node(2);
    // root->right       = new Node(3);
    // root->left->left  = new Node(4);
    // root->left->right = new Node(5);
    cout << "hello" << endl;
    iterativePreorder(root);

    return 0;
}