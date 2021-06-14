#include<bits/stdc++.h>
using namespace std;
int dfs(vector<int> arr[],bool vis[],int size[],int src){
    vis[src] = 1;
    for(auto child:arr[src]){
        if(!vis[child]){
            size[child] = dfs(arr, vis, size, child);
            size[src] += size[child];
        }
    }
    size[src] += 1;
    return size[src];
}
int main(){
    int n, e;
    cin >> n >> e;
    vector<int> arr[n + 1];
    bool vis[n + 1];
    int size[n + 1] = {0};
    while(e--){
        int u, v;
        cin >> u >> v;
        arr[u].push_back(v);
        arr[v].push_back(u);
    }
    int src = 1;
    size[1]=dfs(arr, vis, size, src);
    for (int i = 1; i <= n;i++)
        cout << size[i] << " ";
    return 0;
}