#include<bits/stdc++.h>
using namespace std;
vector<int> arr[10000];
bool vis[10000];
bool checkDfs(int node,int parent){
    vis[node] = true;
    for(int child:arr[node]){
        if(!vis[child])
            return checkDfs(child, node);
        else if(child!=parent)
            return true;
    }
    return false;
}
bool checkBfs(int node,int parent){
    queue<pair<int,int> > q;
    q.push({node,parent});
    vis[node] = true;
    while(!q.empty()){
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();
        for(int x:arr[node]){
            if(!vis[x]){
                vis[x] = true;
                q.push({x,node});
            }
            else if(x!=parent){
                return true;
            }
        }
    }
    return false;
}
int main(){
    int n, e, u, v;
    cin >> n >> e;
    memset(vis, false, n+1);
    while(e--){
        cin >> u >> v;
        arr[u].push_back(v);
        arr[v].push_back(u);
    }
    bool check = false;
    for (int i = 1; i <= n; i++){
        if(!vis[i]){
            if(checkDfs(i,-1)){
                check = true;
                break;
            }
        }
    }
    if(check==true)
        cout << "Cyclic " << endl;
    else
        cout << "Acyclic" << endl;
}