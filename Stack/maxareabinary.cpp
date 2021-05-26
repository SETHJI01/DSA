#include<bits/stdc++.h>
using namespace std;
vector<int> nextsmaller(int arr[],int n){
    vector<int> v;
    stack<int> st;
    for (int i = n - 1; i >= 0;i--){
        while(!st.empty() and arr[i]<=arr[st.top()]){
            st.pop();
        }
        if(st.empty()){
            v.push_back(n);
        }
        else{
            v.push_back(st.top());
        }
        st.push(i);
    }
    reverse(v.begin(), v.end());
    return v;
}
vector<int> prevsmaller(int arr[],int n){
    vector<int> v;
    stack<int> st;
    for (int i = 0; i<n;i++){
        while(!st.empty() and arr[i]<=arr[st.top()]){
            st.pop();
        }
        if(st.empty()){
            v.push_back(-1);
        }
        else{
            v.push_back(st.top());
        }
        st.push(i);
    }
    return v;
}
int MAH(int arr[],int n){
    vector<int> prev, next;
    prev = prevsmaller(arr, n);
    next = nextsmaller(arr, n);
    int weight[n];
    for (int i = 0; i < n;i++){
        weight[i] = next[i] - prev[i] - 1;
    }
    int ans = 0;
    for (int i = 0; i < n;i++){
        int x = weight[i] * arr[i];
        if(ans<x)
            ans = x;
    }
    return ans;
}
int main(){
    int n;
    cin >> n;
    int arr[n][n];
    for (int i = 0; i < n;i++){
        for (int j = 0; j < n;j++){
            cin >> arr[i][j];
        }
    }
    for (int i = 1; i < n;i++){
        for (int j = 0; j < n;j++){
            if(arr[i][j]!=0){
                arr[i][j] += arr[i - 1][j];
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++){
        int x = MAH(arr[i], n);
        if (ans < x)
        {
            ans = x;
        }
    }
    cout << ans << endl;
}