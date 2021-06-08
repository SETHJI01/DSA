#include<bits/stdc++.h>
using namespace std;
vector<int> arr[10000];
bool vis[10000];
bool dfsvis[10000];
bool dfs(int node){
    vis[node] = dfsvis[node] = true;
    for(int child:arr[node]){
        if(!vis[child])
            return dfs(child);
        else if(dfsvis[child])
            return true;
    }
    dfsvis[node] = false;
    return false;
}
int main(){
    int n, e,u,v;
    memset(vis, false, n);
    memset(dfsvis, false, n);
    cin >> n >> e;
    while(e--){
        cin >> u >> v;
        arr[u].push_back(v);
    }
    for (int i = 1; i <= n;i++){
        if(!vis[i]){
            if(dfs(i)){
                cout << "Cycle " << endl;
                return 0;
            }
        }
    }
    cout << "No cycle" << endl;
    return 0;
}