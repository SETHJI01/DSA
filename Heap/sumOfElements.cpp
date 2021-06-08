#include<bits/stdc++.h>
using namespace std;
int main(){
    int n = 6,k1=3,k2=5;
    int arr[] = {1, 3, 12, 5, 15, 11};
    int k = max(k1, k2);
    priority_queue<int> pq;
    for (int i = 0; i < n; i++){
        pq.push(arr[i]);
        if(pq.size()>k)
            pq.pop();
    }
    int n1 = pq.top();
    int diff = abs(k2 - k1);
    while(diff--){
        pq.pop();
    }
    int n2 = pq.top();
    cout << n1 + n2 << endl;
}