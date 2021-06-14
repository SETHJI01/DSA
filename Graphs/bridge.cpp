#include<bits/stdc++.h>
using namespace std;
vector<int> arr[10000];
bool vis[10000];
void dfs(int src, vector<int> &low, vector<int> &dis,int &count,int parent[]){
    vis[src] = true;
    dis[src] = low[src] = ++count;
    for(auto child:arr[src]){
        if(!vis[child]){
            dfs(child, low, dis, count);
            low[src] = min(low[src], low[child]);
            if (low[child] > dis[src]){
                cout << src << " " << child << endl;
            }
        }
        else{
            if(child!=parent[src])
                low[src]=min(low[src],dis[child]);
        }
    }
}
int main(){
    int n, e;
    cin >> n >> e;
    vector<int> dis(n), low(n);
    int count = 0;
    dfs(0, low, dis, count,parent);
    return 0;
}