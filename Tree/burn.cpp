#include<bits/stdc++.h>
using namespace std;
int main(){

}
typedef struct Node{
    int data;
    Node *left, *right;
    Node(int x){
        data = x;
        left = right = NULL;
    }
}Node;
int res = 0;
int burn(Node *root, int leaf, int &dist){
    if(root==NULL)
        return 0;
    if(root->data==leaf){
        dist = 0;
        return 1;
    }
    int ldist = -1, rdist = -1;
    int lh = burn(root, leaf, ldist);
    int rh = burn(root, leaf, rdist);
    if(ldist!=-1){
        dist = ldist + 1;
        res = max(res, rh + dist);
    }
    if(rdist!=-1){
        dist = rdist + 1;
        res = max(res, lh + dist);
    }
    return max(lh, rh) + 1;
}
int main(){
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
}