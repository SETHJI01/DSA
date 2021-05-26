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
//my method segmentation fault
void findSpiral(Node *node)
{
    //Your code here
    if(node==NULL)
        return;
    stack<Node *> st;
    queue<Node *> q;
    q.push(node);
    bool flag = false;
    while (!q.empty()){
        flag = !flag;
        int count = q.size();
        for (int i = 0; i < count;i++){
            Node *temp = q.front();
            q.pop();
            if(flag)
                st.push(temp);
            else{
                cout << temp->data << " ";
            }
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
        if(flag){
            while(!st.empty()){
                cout << st.top()->data << " ";
                st.pop();
            }
        }
    }
}
//gfg method using 2 stack 
//first dusre child ka reverse print krega  and second first ka
void findSpiral2(Node *node)
{
    //Your code here
    stack<Node*> s1, s2;
    s1.push(node);
    vector<int> v;
    while (!s1.empty() || !s2.empty()){
        while(!s1.empty()){
            Node *temp = s1.top();
            s1.pop();
            v.push_back(temp->data);
            if(temp->left)
                s2.push(temp->left);
            if(temp->right)
                s2.push(temp->right);
        }
        while(!s2.empty()){
            Node *temp = s2.top();
            s2.pop();
            v.push_back(temp->data);
            if(temp->left)
                s1.push(temp->left);
            if(temp->right)
                s1.push(temp->right);
        }
    }
}
int main(){
    Node *root = createTree();
    findSpiral(root);
    return 0;
}