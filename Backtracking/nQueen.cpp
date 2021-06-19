#include<bits/stdc++.h>
using namespace std;
bool check(int**arr,int x,int y,int n){
    for (int i = 0; i < x;i++){
        if(arr[i][y]==1)
            return false;
    }
    int i = x;
    int j = y;
    while(i>=0&&j>=0){
        if(arr[i][j]==1)
            return false;
        i--, j--;
    }
    i = x;
    j = y;
    while(i>=0&&j<n){
        if(arr[i][j]==1)
            return false;
        i--, j++;
    }
    return true;
}
bool nQueen(int x,int** arr,int n){
    if(x>=n)
        return true;
    for (int i = 0; i < n; i++)
    {
        if(check(arr,x,i,n)){
            arr[x][i] = 1;
            if(nQueen(x + 1, arr, n)) return true;
            arr[x][i] = 0;
        }
    }
    return false;
}
int main(){
    int n;
    cin >> n;
    int **arr = new int *[n];
    for (int i = 0;i<n;i++){
        arr[i] = new int[n];
        for (int j = 0; j < n;j++){
            arr[i][j] = 0;
        }
    }
    if(nQueen(0,arr,n)){
        for (int i = 0; i < n;i++){
            for (int j = 0; j < n;j++)
                cout << arr[i][j] << " ";
            cout << endl;
        }
    }
    return 0;
}