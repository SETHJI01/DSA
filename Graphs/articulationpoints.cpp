#include<bits/stdc++.h>
using namespace std;
void dfs(vector<int> arr[],bool vis[],int in[],int low[],int node,int parent,vector<int> &v,int &timer){
    vis[node] = true;
    in[node] = low[node] = ++timer;
    int children = 0;
    for (int child : arr[node]){
        if(child==parent)
            continue;
        if(vis[child]){
            low[child] = min(low[child], in[node]);
        }
        else{
            dfs(arr, vis, in, low, child, node, v, timer);
            low[node] = min(low[node], low[child]);
            if(low[child]>=in[node]&&parent!=-1)
                v.push_back(node);
            children++;
        }
    }
    if(parent==-1&&children>1){
        v.push_back(node);
    }
}
int main(){
    int n, e;
    cin >> n >> e;
    vector<int> arr[n + 1];
    bool vis[n + 1];
    int in[n + 1], low[n + 1];
    while (e--){
        int u, v;
        cin >> u >> v;
        arr[u].push_back(v);
        arr[v].push_back(u);
    }
    vector<int> v;
    int timer = 0;
    dfs(arr, vis, in, low, 1,-1, v,timer);
}