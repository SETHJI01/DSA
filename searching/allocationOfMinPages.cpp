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
bool isValid(int check,int arr[],int m,int n){
	int count=1;
	int sum=0;
	for(int i=0;i<n;i++){
		if(arr[i]>check)
			return false;
		else if(sum+arr[i]>check){
			count++;
			sum=arr[i];
			if(count>m)
				return false;
		}
		else
			sum+=arr[i];
	}
	if(count==m)
		return true;
	else
		return false;
}
int allocate(int arr[],int l,int h,int m,int n){
	while(l<=h){
		int mid=l + (h-l)/2;
		bool flag=isValid(mid,arr,m,n);
		if(flag&&!isValid(mid-1,arr,m,n)){
			return mid;
		}
		else if(flag)
			h=mid-1;
		else
			l=mid+1;
	}
	return -1;
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
    while(t--){
    	int n,m;
    	cin>>n>>m;
    	int arr[n];
    	int sum=0;
    	fin {
    		cin>>arr[i];
    		sum+=arr[i];
    	}
    	cout<<allocate(arr,0,sum,m,n);
    }
    return 0;
}