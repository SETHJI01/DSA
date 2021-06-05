#include<bits/stdc++.h>
using namespace std;
int main(){
    priority_queue<int,vector<int>,greater<int> > pq;
    int n,k=3;
    n = 7;
    int counter = 0;
    int arr[] = {6,5,3,2,8,10,9};
    for (int i = 0; i < n;i++){
        pq.push(arr[i]);
        if (pq.size()>k){
            arr[counter++] = pq.top();
            pq.pop();
        }
    }
    while(!pq.empty()){
        arr[counter++] = pq.top();
        pq.pop();
    }
    for (int i = 0; i < n;i++){
        cout << arr[i] << " ";
    }
}