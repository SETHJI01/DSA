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
bool isValid(int arr[],int n,int dist,int m){
	int checkpoint=0;
	int count=1;
	for(int i=1;i<n;i++){
		if(arr[i]-arr[checkpoint]>=dist){
			count++;
			checkpoint=i;
		}
		if(count==m){
			return true;
		}
	}
	return false;
}
int solution(int arr[],int l,int h,int n,int m){
	if(n==0)
		return 0;
	int ans=0;
	while(l<=h){
		int mid=l+(h-l)/2;
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
    int t;
    cin>>t;
    while(t--){
    	int n,m;
    	cin>>n>>m;
    	int arr[n];
    	fin cin>>arr[i];
    	sort(arr,arr+n);
    	cout<<solution(arr,1,arr[n-1]-arr[0],n,m)<<endl;
    }
    return 0;
}