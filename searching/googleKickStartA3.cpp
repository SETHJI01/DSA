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
bool isValid(int mid,int arr[],int n,int s){
	int count=0;
	for(int i=1;i<n;i++){
		count+=(arr[i]-arr[i-1]-1)/mid;
	}
	if(count>s)
		return false;
	else
		return true;
}
int solve(int arr[],int l,int h,int n,int s){
	int res=0;
	while(l<=h){
		int mid=l+(h-l)/2;
		if(isValid(mid,arr,n,s)){
			h=mid-1;
			res=mid;
		}
		else
			l=mid+1;
	}
	return res;
}
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int t;
    cin>>t;
    int c=t;
    while(t--){
    	int n,s;
    	cin>>n>>s;
    	int arr[n],max=0;
    	fin {
    		cin>>arr[i];
    		if(i!=0){
    			if(max<arr[i]-arr[i-1])
    				max=arr[i]-arr[i-1];
    		}
    	}
    	cout<<"Case #"<<c-t<<": "<<solve(arr,1,max,n,s)<<endl;
    }
    return 0;
}