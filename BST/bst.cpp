#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node *left, *right;
    Node(int key){
        data = key;
        left = right = NULL;
    }
};
bool search(Node* root,int key){
    if(root==NULL)
        return false;
    if(key==root->data){
        return true;
    }
    if(key<root->data){
        return search(root->left, key);
    }
    else if(key>root->data){
        return search(root->right, key);
    }
}
Node* r_insert(Node* node,int key){
    if(node==NULL)
        return new Node(key);
    if(key<node->data)
        node->left = r_insert(node->left, key);
    else if(key>node->data)
        node->right = r_insert(node->right, key);
    return node;
}
void inorder(Node *root){
    if(root==NULL)
        return;
    inorder(root->left);
    cout << root->data<<" ";
    inorder(root->right);
}
Node* i_insert(Node* root,int key){
    Node *parent = NULL, *curr = root;
    Node *temp = new Node(key);
    if (curr == NULL)
        return temp;
    while(curr!=NULL){
        parent = curr;
        if(key<curr->data)
            curr = curr->left;
        else if(key>curr->data)
            curr = curr->right;
        else
            return root;
    }
    if(key<parent->data)
        parent->left = temp;
    else
        parent->right = temp;
    return root;
}
Node* getSuccessor(Node* root){
    root = root->right;
    while (root != NULL && root->left != NULL){
        root = root->left;
    }
}
Node* deleteNode(Node* root,int key){
    if(root==NULL)
        return NULL;
    if(key<root->data){
        root->left = deleteNode(root->left, key);
    }
    else if(key>root->data){
        root->right = deleteNode(root->right, key);
    }
    else{
        if(root->left==NULL){
            Node *temp = root;
            root = root->right;
            delete temp;
        }
        else if(root->right==NULL){
            Node *temp = root;
            root = root->left;
            delete temp;
        }
        else{
            Node *temp = getSuccessor(root);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n;i++)
        cin >> arr[i];
    Node *root = NULL;
    for (int i = 0; i < n; i++){
        root=i_insert(root, arr[i]);
    }
    cout << search(root, 13) << " " << search(root, 20) << endl;
    root=deleteNode(root, 13);
    inorder(root);
    cout << endl;
}