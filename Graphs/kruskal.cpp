#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int dist;
    int u, v;
 
    Node(int U,int V,int Dist){
        u = U;
        v = V;
        dist = Dist;
    }
};
int findPar(int node,vector<int> &parent){
    if(node==parent[node]){
        return node;
    }
    return parent[node] = findPar(parent[node],parent);
}
void Union(int u,int v,vector<int> &parent,vector<int> &rank){
    u = findPar(u,parent);
    v = findPar(v,parent);
    if(rank[u]>rank[v]){
        parent[v] = u;
    }
    else if(rank[v]>rank[u]){
        parent[u] = v;
    }
    else{
        parent[v] = u;
        rank[u]++;
    }
}
bool cmp(Node* o1,Node* o2){
    return o1->dist < o2->dist;
}
int main()
{
    int n, e;
    cin >> n >> e;
    vector<Node *> edges;
    for (int i = 0; i < e;i++){
        int u, v, w;
        cin >> u >> v >> w;
        Node *temp = new Node(u, v, w);
        edges.push_back(temp);
    }
    sort(edges.begin(), edges.end(), cmp);
    vector<int> parent(n);
    for (int i = 0; i < n;i++){
        parent[i] = i;
    }
    vector<int> rank(n, 0);
    int cost = 0;
    vector<pair<int, int>> mst;
    for(auto child:edges){
        if(findPar(child->v,parent)!=findPar(child->u,parent)){
            cost += child->dist;
            mst.push_back({child->u, child->v});
            Union(child->u, child->v, parent, rank);
        }
    }
    cout << cost << endl;

}