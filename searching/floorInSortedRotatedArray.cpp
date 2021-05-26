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
int search(int arr[],int l,int h,float key){
	while(l<=h){
		int mid=l +(h-l)/2;
		if(arr[mid]<=key&&arr[mid+1]>key)
			return arr[mid];
		else if(key<arr[mid])
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
    	int n,key;
    	cin>>n;
    	int arr[n];
    	fin cin>>arr[i];
    	cin>>key;
        if(arr[n-1]<key)
            cout<<arr[n-1]<<endl;
        else if(arr[0]>key)
            cout<<-1<<endl;
        else
    	   cout<<search(arr,0,n-1,key);
    }
    return 0;
}