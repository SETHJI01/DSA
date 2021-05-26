//can also be done using stack<pait<int,int> > (prevmax,index)

#include<bits/stdc++.h>
using namespace std;
void solve(int arr[],int n){
    vector<int> v;
    stack<int> st;
    for (int i = 0; i < n;i++){
        while(!st.empty() and arr[i]>=arr[st.top()]){
            st.pop();
        }
        if(st.empty()){
            v.push_back(i+1);
        }
        else{
            v.push_back(i - st.top());
        }
        st.push(i);
    }
    for (int i = 0; i < n;i++){
        cout << v[i] << " ";
    }
}
int main(){
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n;i++){
        cin >> arr[i];
    }
    solve(arr, n);
}