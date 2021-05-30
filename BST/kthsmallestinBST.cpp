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
//naive O(n)
void printkth(Node* root,int k,int &count){
    if(root!=NULL){
        printkth(root->left, k,count);
        count++;
        if(count==k){
            cout << root->data;
            //optimized to O(h+k)
            return;
        }
        printkth(root->right, k,count);
    }
}
//O(h) using augment taking care of left count
//that means we have addede one more property to the node i.e. lcount
//while inserting in left we increment the lcount
Node* insert(Node* root,int x){
    if(root==NULL)
        return new Node(x);
    if(x<root->data){
        root->left = insert(root->left, x);
        root->lcount++;
    }
    else if(x>root>key)
        root->right = insert(root->right, x);
    return root;
}
Node* kth(Node* root,int k){
    if(root==NULL)
        return;
    int count = root->lcount + 1;
    if(k==count)
        return root;
    if(count>k)
        return kth(root->left, k);
    return kth(root->left, k - count);
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
        root=r_insert(root, arr[i]);
    }
    int count = 0;
    printkth(root, 2, count);
    inorder(root);
    cout << endl;
}