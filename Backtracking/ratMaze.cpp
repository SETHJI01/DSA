#include<bits/stdc++.h>
using namespace std;
bool check(int x,int y,vector<vector<int> > grid){
    int n = grid.size();
    if(x<n&&y<n&&grid[x][y]!=0)
        return true;
    return false;
}
bool solveMaze(int x,int y,vector<vector<int> > grid,int n,vector<vector<int> >&sol){
    sol[x][y] = 1;
    if(x==n-1&&y==n-1){
        return true;
    }
    if(check(x+1,y,grid)&&solveMaze(x+1,y,grid,n,sol)){
        return true;
    }
    if(check(x,y+1,grid)&&solveMaze(x,y+1,grid,n,sol))
        return true;
    sol[x][y] = 0;
    return false;
}
int main(){
    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int>(n));
    vector<vector<int>> sol(n, vector<int>(n));
    for (int i = 0; i < n;i++){
        for (int j = 0; j < n;j++){
            cin >> v[i][j];
        }
    }
    if(v[0][0]==0)
        cout << "NO" << endl;
    else{
        cout << solveMaze(0, 0, v, n,sol)<<endl;
        for (int i = 0; i < n;i++){
            for (int j = 0; j < n;j++){
                cout << sol[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}