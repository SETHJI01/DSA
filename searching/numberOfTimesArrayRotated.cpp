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
int countR(int arr[],int l,int h,int n){
	while(l<=h){
		int mid=l + (h-l)/2;
		int next=(mid+1)%n;
		int prev=(mid-1+n)%n;
		if(arr[mid]<=arr[prev]&&arr[mid]<=arr[next])
			return n-mid;
		else if(arr[mid]<arr[h])
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
    	int n;
    	cin>>n;
    	int arr[n];
    	fin cin>>arr[i];
    	if(arr[0]<arr[n-1]){
    		cout<<"Array is not rotated "<<endl;
    	}
    	else{
    		int ans=countR(arr,0,n-1,n);
    		cout<<ans<<endl;
    	}
    }
    return 0;
}