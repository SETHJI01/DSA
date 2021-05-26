#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define fin for(int i=0;i<n;i++)
#define ff first
#define ss second
#define vi vector<int>
#define vc vector<char>
#define vii vector<int,int>
#define pb push_back`
#define mp make_pair
int search(int arr[],int l,int h,int key){
	while(l<=h){
		int mid = l + (h-l)/2;
		if(arr[mid]==key)
			return mid;
		else if(arr[l]<=key&&arr[mid]>=key)
			h=mid-1;
		else if(arr[mid]<=key&&arr[h]>=key)
			l=mid+1;
		else if(arr[mid]>=key&&arr[h]<=key){
			l=mid+1;
		}
		else
			h=mid-1;
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
    	cout<<"key "<<key<<" is found at index "<<search(arr,0,n-1,key);
    }
    return 0;
}