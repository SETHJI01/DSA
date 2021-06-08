#include<bits/stdc++.h>
#define ppi pair<int,pair<int,int> >
using namespace std;
int main(){
    int k = 2;
    int arr[4][2] = {4, 2, 3, 2, 1, 1, 0, 1};
    priority_queue<ppi> pq;
    for (int i = 0; i < 4;i++){
        int dist = pow(arr[i][0], 2) + pow(arr[i][1], 2);
        pq.push({dist,{arr[i][0],arr[i][1]}});
        if(pq.size()>k)
            pq.pop();
    }
    while(!pq.empty()){
        cout << pq.top().second.first << " "<<pq.top().second.second << endl;
        pq.pop();
    }
}
