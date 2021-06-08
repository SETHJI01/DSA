#include<bits/stdc++.h>
using namespace std;
vector<int> arr[1000];
bool vis[1000];
void dfs(int i, stack<int> &st){
    vis[i] = true;
    for (int x : arr[i]){
        if(!vis[x])
            dfs(x,st);
    }
    st.push(i);
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
    stack<int> st;
    for (int i = 0; i <= n;i++){
        if(!vis[i]){
            dfs(i, st);
        }
    }
    while(!st.empty()){
        cout << st.top()<<" ";
        st.pop();
    }
    return 0;
}