#include<bits/stdc++.h>
using namespace std;
int maxcut(int n,int a,int b,int c){
    if(n==0)
        return 0;
    if(n<0)
        return -1;
    int res=max(maxcut(n-a,a,b,c),max(maxcut(n-b,a,b,c),maxcut(n-c,a,b,c)));
    if(res<0)
        return -1;
    else
        return res+1;
}
int main(){
    int n=5,a=2,b=3,c=1;
    cout<<maxcut(n,a,b,c);
}
