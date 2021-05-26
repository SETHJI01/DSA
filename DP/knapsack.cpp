#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fin for(int i=0;i<n;i++)
#define ff first
#define ss second
#define pb push_back
#define ppb pop_back
#define vi vector<int>
#define vc vector<char>
#define vii vector< pair<int,int> >
int dp[10000][10000];
//recursive
int knapsack(int w[],int val[],int c,int n){
	if(n==0||c==0)
		return 0;
	if(c>=w[n-1]){
		return max(val[n-1]+knapsack(w,val,c-val[n-1],n-1),knapsack(w,val,c,n-1));
	}
	else
		return knapsack(w,val,c,n-1);
}
// memoized
int knapsack2(int w[],int val[],int c,int n){
	if(n==0||c==0)
		return 0;
	if(dp[c][n]!=-1)
		return dp[w][n];
	if(c>=w[n-1])
		return dp[c][n]=max(val[n-1]+knapsack2(w,val,c-val[n-1],n-1),knapsack2(w,val,c,n-1));
	else
		return dp[c][n]=knapsack2(w,val,c,n-1);
}
//topdown
int knapsack3(int w[],int val[],int c,int n){
	for(int i=0;i<=n;i++)
		dp[0][i]=0;
	for(int i=0;i<=w;i++)
		dp[i][0]=0;
	for(int i=1;i<=w;i++){
		for(int j=1;j<=n;j++){
			if(i>=w[j-1])
				t[i][j]=max(val[j-1]+t[i-w[j-1]][j-1],t[i][j-1]);
			else
				t[i][j]=t[i][j-1];
		}
	}
	return dp[w][n];
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    memset(dp,-1,sizeof(dp));

    return 0;
}