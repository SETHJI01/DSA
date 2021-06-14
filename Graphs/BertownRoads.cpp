#include<bits/stdc++.h>
using namespace std;
bool hasBridge;
void dfs(vector<int> arr[], int in[], int low[], int &count, bool vis[], int src, int parent)
{
    in[src] = low[src] = ++count;
    vis[src] = true;
    for (int child : arr[src]){
        if(child==parent)
            continue;
        if (!vis[child])
        {
            dfs(arr, in, low, count, vis, child,src);
            if(low[child]>in[src]){
                hasBridge = true;
                return;
            }
            low[src] = min(low[src], low[child]);
            cout << src << " " << child << endl;
        }
        else {
            low[child] = min(low[child], in[src]);
            if(in[child]>in[src])//to check the descendant
                cout << src << " " << child << endl;
        }
    }
}
int main()
{
    int n, e;
    cin >> n >> e;
    vector<int> arr[n + 1];
    bool vis[n + 1];
    while (e--){
        int u, v;
        cin >> u >> v;
        arr[u].push_back(v);
        arr[v].push_back(u);
    }
    int in[n + 1];
    int low[n + 1];
    int count = 0, src = 1;
    dfs(arr, in, low, count, vis, src,-1);
    return 0;
}