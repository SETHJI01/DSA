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
int width(Node* node){
    queue<Node *> q;
    q.push(node);
    int max = 0;
    while (!q.empty())
    {
        int count = q.size();
        if(count>max)
            max = count;
        for (int i = 0; i < count; i++)
        {
            Node *temp = q.front();
            q.pop();
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
    }
    return max;
}
int main(){
    Node *root = createTree();
    cout<<"Max width = "<<width(root)<<endl;
    return 0;
}