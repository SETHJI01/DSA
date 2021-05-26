#include<iostream>
#include<queue>
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
void print(Node* node,int k,int k1){
    if(node==NULL)
        return;
    if (k == k1){
        cout<<node->data<<" ";
        return;
    }
    print(node->left,k,k1+1);
    print(node->right,k,k1+1);
}
int height(Node* node){
    if(node==NULL)
        return 0;
    else
        return max(height(node->left), height(node->right)) + 1;
}

void levelOrder(Node* node){
    queue<Node*> q;
    q.push(node);
    while(!q.empty()){
        Node *temp = q.front();
        q.pop();
        cout << temp->data << " ";
        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);
    }
}
//using null as a indicator of level end
void levelOrderLineByLine1(Node* node){
    queue<Node *> q;
    q.push(node);
    q.push(NULL);
    bool check = true;
    while (q.size() > 1)
    {
        Node *temp = q.front();
        q.pop();
        if(temp){
            if(check==true)
                cout << temp->data << " ";
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
            check = false;
        }
        else{
            q.push(NULL);
            cout << endl;
            check = true;
        }
    }
}
void levelOrderLineByLine2(Node* node){
    queue<Node *> q;
    q.push(node);
    while(!q.empty()){
        int count = q.size();
        for (int i = 0; i < count;i++){
            Node *temp = q.front();
            q.pop();
            cout << temp->data << " ";
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
        cout << endl;
    }
}
void printleftview(Node* node){
    queue<Node *> q;
    q.push(node);
    while(!q.empty()){
        int count = q.size();
        for (int i = 0; i < count;i++){
            Node *temp = q.front();
            q.pop();
            if(i==0)
                cout << temp->data << " ";
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
    }
}
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
int size(Node* node){
    if(node==NULL)
        return 0;
    return size(node->left) + size(node->right) + 1;
}
int maximum(Node* node){
    if(node==NULL)
        return 0;
    return max(max(maximum(node->right),maximum(node->left)),node->data);
}
bool childsum(Node* node){
    if(node->left==NULL&&node->right==NULL){
        return true;
    }
    int sum = 0;
    if(node->left)
        sum += node->left->data;
    if(node->right)
        sum += node->right->data;
    if(sum==node->data&&childsum(node->left)&&childsum(node->right))
        return true;
    return false;
}
// int height(Node* node){
//     if(node==NULL)
//         return 0;
//     return max(height(node->left), height(node->right)) + 1;
// }

// //O(n^2) as balance check each height and each height is found in O(n);

// bool balanced(Node *node)
// {
//     if(node->left==NULL&&node->right==NULL)
//         return true;
//     int x = abs(height(node->left) - height(node->right));
//     if (balanced(node->left) && balanced(node->right) && x<=1)
//         return true;
//     return false;
// }

//O(n) using pair
pair<bool,int> balanced2(Node* node){
    if (node->left == NULL && node->right == NULL){
        // p.first = true;
        // p.second = 1;
        return {true,1};
    }
    pair<bool, int> p1,p2;
    p1 = balanced2(node->left);
    p2 = balanced2(node->right);
    if (p1.first&&p2.first&&abs(p1.second-p2.second)<=1){
        return {true, max(p1.second, p2.second)+1};
    }
    return {false, max(p1.second, p2.second)+1};
}
int main(){
    Node *root = createTree();
    // inorder(root);
    // cout << endl;
    // // cout << height(root) << endl;
    // // int n;
    // // cout << "Enter the level you want to print ";
    // // cin >> n;
    // // print(root, n, 0);
    // levelOrder(root);
    // // cout << endl;
    // levelOrderLineByLine1(root);
    // levelOrderLineByLine2(root);
    // cout << maximum(root) << endl;
    pair<bool, int> p = balanced2(root);
    if(p.first)
        cout << "Balanced with height " << p.second << endl;
    else
        cout << "Not Balanced " << endl;
}