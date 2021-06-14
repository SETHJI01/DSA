#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int> > arr[10000];
int dist[10000];
void addEdge(int u,int v,int d){
    arr[u].push_back({v, d});
}
void dijakstra(int src,int d){
    priority_queue<pair<int,int> , vector<pair<int,int> >, greater<pair<int,int> > > pq;
    pq.push({d, src});
    while(!pq.empty()){
        auto temp = pq.top();
        pq.pop();
        for(auto child:arr[temp.second]){
            if(dist[child.first]>temp.first+child.second){
                dist[child.first] = temp.first + child.second;
                pq.push({dist[child.first],child.first});
            }
        }
    }
}
int main(){
    int n = 5;
    for (int i = 0; i <= n; i++){
        dist[i] = INT_MAX;
    }
    addEdge(0, 1, 5);
    addEdge(0, 2, 3);
    addEdge(1, 3, 6);
    addEdge(1, 2, 2);
    addEdge(2, 4, 4);
    addEdge(2, 5, 2);
    addEdge(2, 3, 7);
    addEdge(3, 4, 1);
    addEdge(4, 5, 2);
    dist[0] = 0;
    dijakstra(0, dist[0]);
    for (int i = 0; i <= n; i++)
        cout << dist[i] << endl;
}