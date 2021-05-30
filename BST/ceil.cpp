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
int findCeil(Node* root,int key){
    int ans = -1;
    Node *curr = root;
    while(curr!=NULL){
        if(key<curr->data){
            if(ans!=-1)
                ans = min(ans,curr->data);
            else
                ans = curr->data;
            curr = curr->left;
        }
        else if(key>curr->data){
            curr = curr->right;
        }
        else
            return curr->data;
    }
    return ans;
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
    int t;
    cin >> t;
    while (t--){
        int key;
    cout << "Key : ";
    cin >> key;
    cout << findCeil(root, key)<<endl;
    }
    inorder(root);
    cout << endl;
}