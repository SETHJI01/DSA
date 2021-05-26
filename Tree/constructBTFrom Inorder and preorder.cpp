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
int pres = 0;
Node *createTree(int In[], int ins, int ine, int Pre[], int pree){
    if(ins<=ine&&pres<=pree){
    int x = Pre[pres];
    pres++;
    Node *node = new Node(x);
    int s = 0;
    for (int i = ins; i <= ine;i++){
        if(In[i]==x){
            s = i;
            break;
        }
    }
    node->left = createTree(In, ins, s - 1, Pre, pree);
    node->right = createTree(In, s+1, ine, Pre, pree);
    return node;
    }
    else{
        return NULL;
    }
}
void inorder(Node* node){
    if(node==NULL)
        return;
    inorder(node->left);
    cout << node->data << " ";
    inorder(node->right);
}
int main(){
    int In[] = {40, 20, 60, 50, 70, 10, 80, 100, 30};
    int Pre[] = {10, 20, 40, 50, 60, 70, 30, 80, 100};
    Node *root = createTree(In,0,8,Pre,8);
    inorder(root);
    return 0;
}