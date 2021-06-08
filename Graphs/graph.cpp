#include<bits/stdc++.h>
using namespace std;
vector<int> arr[1000];
bool vis[1000];
vector<int> bfsOfGraph(int n){
    vector<int> bfs;
    int count = 0;
    for (int i = 1; i <= n; i++){
        if(!vis[i]){
            count++;
            vis[i] = true;
            queue<int> q;
            q.push(i);
            while (!q.empty())
            {
                int temp = q.front();
                q.pop();
                bfs.push_back(temp);
                for (int x : arr[temp]){
                    if(!vis[x]){
                        vis[x] = true;
                        q.push(x);
                    }
                }
            }
        }
    }
    cout << count << endl;
    return bfs;
}
void dfs(int i){
    cout << i << " ";
    for (int x:arr[i]){
        if(!vis[x])
            dfs(x);
    }
}
int main(){
    int n, e;
    cin >> n >> e;
    memset(vis, false, n+1);
    while (e--){
        int u, v;
        cin >> u >> v;
        arr[u].push_back(v);
    }
    vector<int> v = bfsOfGraph(n);
    for (int i = 0; i < v.size();i++){
        cout << v[i] << " ";
    }
    return 0;
}