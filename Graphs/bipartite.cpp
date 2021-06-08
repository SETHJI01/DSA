#include<bits/stdc++.h>
using namespace std;
vector<int> arr[1000];
int color[1000];
bool checkBipartiteBfs(){
    queue<int> q;
    q.push(1);
    color[1] = 0;
    while (!q.empty()){
        int node = q.front();
        q.pop();
        for (int child : arr[node]){
            if(color[child]==-1){
                color[child] = (color[node] == 0) ? 1 : 0;
                q.push(child);
            }
            else if(color[child]==color[node])
                return true;
        }
    }
    return false;
}
bool checkBipartiteDfs(int node,int parent){
    if(color[parent]==-1)
        color[node] = 0;
    else
        color[node] = (color[parent] == 0) ? 1 : 0;
    for(int child:arr[node]){
        if(color[child]==-1)
            return checkBipartiteDfs(child, node);
        else if(color[child]==color[node])
            return true;
    }
    return false;
}
int main()
{
    memset(color, -1, sizeof(color));
    int n, e;
    cin >> n >> e;
    while(e--){
        int u, v;
        cin >> u >> v;
        arr[u].push_back(v);
        arr[v].push_back(u);
    }
    if (checkBipartiteDfs(1,0))
        cout << "Bipartite" << endl;
    else
        cout << "Not a Bipartite " << endl;
}