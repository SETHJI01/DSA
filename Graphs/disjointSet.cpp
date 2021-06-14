#include<bits/stdc++.h>
using namespace std;
int parent[100000];
int Rank[100000];
void makeset(int n){
    for (int i = 0; i <= n;i++){
        parent[i] = i;
        Rank[i] = 0;
    }
}
int findPar(int node){
    if(node==parent[node]){
        return node;
    }
    return parent[node] = findPar(parent[node]);
}
void Union(int u,int v){
    u = findPar(u);
    v = findPar(v);
    if(Rank[u]>Rank[v]){
        parent[v] = u;
    }
    else if(Rank[v]>Rank[u]){
        parent[u] = v;
    }
    else{
        parent[v] = u;
        Rank[u]++;
    }
}