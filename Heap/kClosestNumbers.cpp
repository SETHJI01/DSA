#include<bits/stdc++.h>
using namespace std;
int main(){
    priority_queue<pair<int, int>> pq;
    int n = 5, X = 7,k=3;
    int arr[] = {5, 6, 7, 8, 9};
    for (int i = 0; i < n;i++){
        pq.push({abs(arr[i] - X), arr[i]});
        if(pq.size()>k){
            pq.pop();
        }
    }
    while(!pq.empty()){
        cout << pq.top().second << " ";
        pq.pop();
    }
}