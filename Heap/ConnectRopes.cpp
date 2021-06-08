#include<bits/stdc++.h>
using namespace std;
int main(){
    int n=5;
    int arr[] = {1, 2, 3, 4, 5};
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n;i++){
        pq.push(arr[i]);
    }
    int cost = 0;
    while (pq.size() != 1){
        int t = pq.top();
        pq.pop();
        int s = pq.top();
        pq.pop();
        int sum = t + s;
        cost += sum;
        pq.push(sum);
    }
    cout << cost << endl;
}