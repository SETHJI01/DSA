#include<bits/stdc++.h>
using namespace std;
int main(){
    int n = 15, k = 3;
    int arr[] = {1, 1, 1, 1, 1, 2, 2, 2, 4, 4, 4, 5, 5, 4,5};
    unordered_map<int, int> mp;
    for (int i = 0; i < 15;i++){
        mp[arr[i]]++;
    }
    for(auto x:mp)
        cout << x.first << " ";
    cout << endl;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (auto x : mp){
        pq.push({x.second, x.first});
        if(pq.size()>k)
            pq.pop();
    }
    while(!pq.empty()){
        cout << pq.top().second << " " << pq.top().first << endl;
        pq.pop();
    }
}