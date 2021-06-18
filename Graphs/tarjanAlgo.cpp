#include<bits/stdc++.h>
using namespace std;
vector<int> arr[1001];
bool vis[1001], onStack[1001];
stack<int> st;
int in[1001], low[1001];
int SCC = 0;
void dfs(int node)
{
    vis[node] = true;
    onStack[node] = true;
    st.push(node);
    for (int child : arr[node])
    {
        if(vis[child]&&onStack[child])
            low[node] = min(low[node], in[child]);
        else{
            if(!vis[child]){
                dfs(child);
                if(onStack[child])
                    low[node] = min(low[node], low[child]);
            }
        }
    }
    if(in[node]==low[node]){
        SCC++;
        cout << "SCC #" << SCC << endl;
        int u;
        while(1){
            u = st.top();
            st.pop();
            cout << u << " ";
            if(u==node)
                break;
        }
        cout << endl;
    }
}
int main(){
    int n, e;
    cin >> n >> e;
    while(e--){
        int u, v;
        cin >> u >> v;
        arr[u].push_back(v);
    }
    for (int i = 1; i <=n;i++)
        if(!vis[i])
            dfs(i);
}