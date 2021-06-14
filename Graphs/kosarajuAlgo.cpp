//To find all the connected components;
#include<bits/stdc++.h>
using namespace std;
vector<int> arr[100000];
bool vis[10000];
void dfs(int node, stack<int> &st){
    vis[node] = true;
    for(auto child:arr[node]){
        if(!vis[child]){
            dfs(child, st);
        }
    }
    st.push(node);
}
int main(){
    int n, e;
    cin >> n >> e;
    while(e--){
        int u, v;
        cin >> u >> v;
        arr[u].push_back(v);
    }
    stack<int> st;
    dfs(0, st);
     
    
}