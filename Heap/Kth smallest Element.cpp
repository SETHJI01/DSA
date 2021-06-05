#include<bits/stdc++.h>
using namespace std;
int main(){
    priority_queue<int> pq;
    int n,val,k;
    cin >> n>>k;
    for (int i = 0; i < n;i++){
        cin >> val;
        pq.push(val);
        if(pq.size()>k)
            pq.pop();
    }
    cout << pq.top() << endl;
}