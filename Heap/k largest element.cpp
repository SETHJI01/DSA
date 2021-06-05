#include<bits/stdc++.h>
using namespace std;
int main(){
    priority_queue<int,vector<int>,greater<int> > pq;
    int n,k=3;
    n = 8;
    int arr[] = {10, 20, 90, 33, 41, 22, 3, 9};
    for (int i = 0; i < n;i++){
        pq.push(arr[i]);
        if(pq.size()>k)
            pq.pop();
    }
    while(!pq.empty()){
        cout << pq.top() << endl;
        pq.pop();
    }
}