//improved
#include<bits/stdc++.h>
using namespace std;
vector<pair<int, int>> arr[10000];
void printMST(int V){
    int parent[V];
    bool mstSet[V];
    int key[V];
    for (int i = 0; i < V;i++)
        key[i] = INT_MAX, parent[i] = -1,mstSet[i]=false;
    key[0] = 0;
    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;
    pq.push({0, 0});
    for (int i = 0; i < V-1;i++){
        int node = pq.top().second;
        pq.pop();
        mstSet[node] = true;
        for(auto child:arr[node]){
            int ch = child.first;
            int d = child.second;
            if (mstSet[ch] == false&&key[ch]>d){
                key[ch] = d, parent[ch] = node;
                pq.push({d, ch});
            }
        }
    }
    for (int i = 1; i < V;i++){
        cout << parent[i] << " " << i << endl;
    }
}
void addEdge(int u,int v,int d){
    arr[u].push_back({v,d});
    arr[v].push_back({u,d});
}
int main(){
    int V = 9;
    addEdge( 0, 1, 4);
    addEdge( 0, 7, 8);
    addEdge( 1, 2, 8);
    addEdge( 1, 7, 11);
    addEdge( 2, 3, 7);
    addEdge( 2, 8, 2);
    addEdge( 2, 5, 4);
    addEdge( 3, 4, 9);
    addEdge( 3, 5, 14);
    addEdge( 4, 5, 10);
    addEdge( 5, 6, 2);
    addEdge( 6, 7, 1);
    addEdge( 6, 8, 6);
    addEdge( 7, 8, 7);
    printMST(V);
}