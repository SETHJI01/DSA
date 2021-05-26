#include<bits/stdc++.h>
using namespace std;
//O(n2) using 2 array known(incoming) and knows(outgoing)
int celebrity1(vector<vector<int> > arr,int n){
    int incoming[n] = {0};
    int outgoing[n] = {0};
    for (int i = 0; i < n;i++){
        for (int j = 0; j < n;j++){
            if(arr[i][j]==1){
                incoming[j]++;
                outgoing[i]++;
            }
        }
    }
    int ans;
    for (int i = 0; i < n; i++){
        if(incoming[i]==n-1){
            ans = i;
            break;
        }
    }
    if(outgoing[ans]==0){
        return ans;
    }
    return -1;
}
//o(n) stack using elemination
int celebrity2(vector<vector<int> > arr,int n){
    stack<int> stk;
    for (int i = 0; i < n; i++){
        stk.push(i);
    }
    while(stk.size()!=1){
        int a = stk.top();
        stk.pop();
        int b = stk.top();
        stk.pop();
        if(arr[a][b]==1){
            stk.push(b);
        }
        else
            stk.push(a);
    }
    int ans = stk.top();
    for (int i = 0; i < n;i++){
        if(arr[ans][i]==1){
            return -1;
        }
    }
    for (int i = 0; i < n;i++){
        if(i!=ans&&arr[i][ans]==0)
            return -1;
    }
    return ans;
}
int main(){
    int n;
    cin >> n;
    vector<vector<int> > arr;
    for (int i = 0; i < n;i++){
        for (int j = 0; j < n;j++){
            cin >> arr[i][j];
        }
    }
    cout << celebrity1(arr,n);
}