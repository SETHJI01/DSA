#include<bits/stdc++.h>
using namespace std;
vector<int> arr[1000];
bool vis[1000];
int indegree[1000];
void Kahn(queue<int> &q){
    while(!q.empty()){
        int temp=q.front();
        q.pop();
        cout << temp << " ";
        vis[temp] = true;
        for(int child:arr[temp]){
            if(!vis[child]){
                indegree[child]--;
                if(indegree[child]==0)
                    q.push(child);
            }
        }     
    }
}
int main(){
    int n,e;
    cin >> n >> e;
    memset(vis, false, n+1);
    memset(indegree, 0, n + 1);
    while (e--){
        int u, v;
        cin >> u >> v;
        arr[u].push_back(v);
        indegree[v]++;
    }
    queue<int> q;
    for (int i = 0; i <= n;i++){
        if(indegree[i]==0)
            q.push(i);
    }
    Kahn(q);
}