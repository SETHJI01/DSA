#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fin for(int i=0;i<n;i++)
#define ff first
#define ss second
#define vi vector<int>
#define vc vector<char>
#define vii vector<int,int>
#define pb push_back
#define mp make_pair
bool isValid(ll arr[],ll n,ll height,ll m){
	ll ans=0;
	for(int i=0;i<n;i++){
		if(arr[i]>height)
			ans+=abs(height-arr[i]);
	}
	if(ans>=m)
		return true;
	else
		return false;
}
ll solution(ll arr[],ll l,ll h,ll m,ll n){
	ll ans=0;
	while(l<=h){
		ll mid= l + (h-l)/2;
		if(isValid(arr,n,mid,m)){
			ans=mid;
			l=mid+1;
		}
		else
			h=mid-1;
	}
	return ans;
}
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    	ll n;
    	ll m;
    	cin>>n>>m;
    	ll arr[n];
    	ll min=INT_MAX,max=0;
    	fin{
    		cin>>arr[i];
    		if(min>arr[i])
    			min=arr[i];
    		if(max<arr[i])
    			max=arr[i];
    	}
    	cout<<solution(arr,min,max,m,n)<<endl;
    return 0;
}