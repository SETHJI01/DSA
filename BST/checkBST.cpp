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
void inorder(Node* node){
    if(node==NULL)
        return;
    inorder(node->left);
    cout << node->data << " ";
    inorder(node->right);
}
//method 1 inefficient O(n^2)
//implemented check method1 using lmax,lmin
int lmax(Node* root){
    if(root==NULL)
        return 0;
    else return max(max(lmax(root->left),lmax(root->right)),root->data);
}
int rmin(Node* root){
    if(root==NULL)
        return INT_MAX;
    else return min(min(rmin(root->left),rmin(root->right)),root->data);
}
bool checkBST1(Node* root){
    if(root==NULL)
        return true;
    if(checkBST1(root->left)&&checkBST1(root->right)){
        int a = lmax(root->left);
        int b = rmin(root->right);
        if(root->data>=b||root->data<=a)
            return false;
        return true;
    }
    return false;
}
//Method 2 
//using the ranges for every node
bool checkBST2(Node* root,int min,int max){
    if(root==NULL)
        return true;
    bool p1 = checkBST2(root->left, min, root->data);
    bool p2 = checkBST2(root->right, root->data, max);
    if(root->data<=min||root->data>=max)
        return false;
    return p1 && p2;
}

//Method #
//using inorder Traversal and comparing the prev element traversed with current one
void checkBST3(Node* root,bool &check,int &ans){
    if(root==NULL){
        return;
    }
    checkBST3(root->left, check,ans);
    if(root->data<ans){
        check = false;
        return;
    }
    ans = root->data;
    checkBST3(root->right, check, ans);
}
int main()
{
    Node *root = new Node(20);
    root->left = new Node(8);
    root->left->right = new Node(10);
    root->right = new Node(25);
    root->right->left = new Node(23);
    root->right->right = new Node(35);
    bool check = true;
    int ans = -1;
}