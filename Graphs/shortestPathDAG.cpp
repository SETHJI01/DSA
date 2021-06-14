#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int> > arr[10000];
int vis[10000] = {0};
int dist[10000];
void addEdge(int u,int v,int d){
    arr[u].push_back({v, d});
}
void topo(stack<int> &s,int src){
    vis[src] = 1;
    for(auto child:arr[src]){
        if(!vis[child.first]){
            topo(s, child.first);
        }
    }
    s.push(src);
}
int main(){
    int n;
    cin >> n;
    for (int i = 0; i <= n;i++){
        dist[i] = INT_MAX;
    }
    addEdge(0, 1, 5);
    addEdge(0, 2, 3);
    addEdge(1, 3, 6);
    addEdge(1, 2, 2);
    addEdge(2, 4, 4);
    addEdge(2, 5, 2);
    addEdge(2, 3, 7);
    addEdge(3, 4, 1);
    addEdge(4, 5, 2);
    stack<int> s;
    dist[0] = 0;
    topo(s, 0);
    while(!s.empty()){
        int temp = s.top();
        s.pop();
        //if it is reached previously
        if (dist[temp] != INT_MAX)
        {
            for (auto child : arr[temp])
            {
                if (dist[child.first]> dist[temp])
                {
                    dist[child.first] = dist[temp] + child.second;
                }
            }
        }
    }
    for (int i = 0; i <= 5;i++)
        cout << dist[i] << " ";
}