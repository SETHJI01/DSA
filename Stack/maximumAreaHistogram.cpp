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
int main(){
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n;i++){
        cin >> arr[i];
    }
    vector<int> prev, next;
    prev = prevsmaller(arr, n);
    next = nextsmaller(arr, n);
    int ans = 0;
    for (int i = 0; i < n; i++){
        int x = (next[i] - prev[i]-1) * arr[i];
        if(ans<x)
            ans = x;
    }
    for (int i = 0; i < n; i++){
        cout << prev[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < n; i++){
        cout << next[i] << " ";
    }
    cout << endl;
    cout << ans << endl;
}