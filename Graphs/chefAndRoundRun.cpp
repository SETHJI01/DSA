#include<bits/stdc++.h>
using namespace std;
vector<int> arr[1000001];
vector<int> tr[1000001];
vector<int> scc, order;
bool vis[1000001];
int A[1000001];
void dfs(int node){
    vis[node] = true;
    for(auto child:arr[node]){
        if(!vis[child])
            dfs(child);
    }
    order.push_back(node);
}
void dfs1(int node){
    vis[node] = true;
    for(int child:tr[node]){
        if(!vis[child])
            dfs1(child);
    }
    scc.push_back(node);
}
int main(){
    int t, n, res;
    cin >> t;
    while(t--){
        cin >> n;
        order.clear(), res = 0;
        for (int i = 1; i <= n;i++){
            arr[i - 1].clear(), tr[i - 1].clear(), vis[i - 1] = false;
            cin >> A[i - 1];
        }
        for (int i = 0; i < n;i++){
            int a = i;
            int b = (i + A[i]+1) % n;
            arr[a].push_back(b);
            tr[b].push_back(a);
        }
        for (int i = 1; i <= n;i++){
            if(!vis[i-1]){
                dfs(i - 1);
            }
        }
        for (int i = 0; i < n;i++)
            vis[i] = false;
        reverse(order.begin(), order.end());
        for(int i:order){
            scc.clear();
            dfs1(i);
            if(scc.size()==1&&(scc[0]!=arr[scc[0]][0]))
                continue;
            res += scc.size();
        }
        cout << res << endl;
    }
}