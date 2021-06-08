#include<bits/stdc++.h>
using namespace std;
int main(){
    int n = 7;
    int arr[] = {12, 15, 10, 5, 8, 7, 16};
    priority_queue<int> minh;
    priority_queue<int, vector<int>, greater<int>> maxh;
    minh.push(arr[0]);
    cout << arr[0] << " ";
    for (int i = 1; i < n; i++){
        if(minh.size()>maxh.size()){
            if(minh.top()>arr[i]){
                maxh.push(minh.top());
                minh.pop();
                minh.push(arr[i]);
                
            }
            else{
                maxh.push(arr[i]);
            }
            cout << (minh.top() + maxh.top()) / 2.0 << " ";
        }
        else{
            if(arr[i]<=minh.top())
                minh.push(arr[i]);
            else{
                maxh.push(arr[i]);
                minh.push(maxh.top());
                maxh.pop();
            }
            cout << minh.top() << " ";
        }
    }
    return 0;
}