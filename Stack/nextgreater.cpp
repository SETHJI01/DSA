#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n;i++)
        cin >> arr[i];
    stack<int> st;
    vector<int> v;
    for (int i = n - 1; i >= 0; i--){
        while(!st.empty() and arr[i]>=st.top()){
            st.pop();
        }
        if(st.empty())
            v.push_back(-1);
        else
            v.push_back(st.top());
        st.push(arr[i]);
    }
    reverse(v.begin(), v.end());
    for (int i = 0; i < n;i++){
        cout << v[i] << " ";
    }
}