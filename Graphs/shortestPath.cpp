#include<bits/stdc++.h>
using namespace std;
vector<int> arr[10000];
int dist[10000];
void shortestPath(int src){
    queue<int> q;
    q.push(src);
    dist[src] = 0;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto child:arr[node]){
            if(dist[child]>dist[node]+1){
                dist[child] = dist[node] + 1;
                q.push(child);
            }
        }
    }
}
void spath(int node,int d){
    dist[node] = d;
    for(int child:arr[node]){
        if(dist[child]>dist[node]+1)
            spath(child, dist[node] + 1);
    }
}
int main()
{
    int n, e, u, v;
    cin >> n >> e;
    for (int i = 0; i <= n;i++)
        dist[i] = INT_MAX;
    while (e--)
    {
        cin >> u >> v;
        arr[u].push_back(v);
        arr[v].push_back(u);
        }
    int src = 0;
    spath(src, 0);
    for (int i = 0; i <= n; i++){
        cout << dist[i] << " ";
    }
}