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
int firstsearch(int arr[],int l,int h,int key){
	if(l<=h){
		int mid=l+(h-l)/2;
		if(arr[mid]==key&&arr[mid-1]!=key)
			return mid;
		else if(arr[mid]<key)
			return firstsearch(arr,mid+1,h,key);
		else
			return firstsearch(arr,l,mid-1,key);
	}
	return -1;
}
int lastsearch(int arr[],int l,int h,int key){
	if(l<=h){
		int mid=l+(h-l)/2;
		if(arr[mid]==key&&arr[mid+1]!=key)
			return mid;
		else if(arr[mid]>key)
			return lastsearch(arr,l,mid-1,key);
		else
			return lastsearch(arr,mid+1,h,key);
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
    	cout<<"First Occurence Of element "<<key<<" is "<<firstsearch(arr,0,n-1,key);
    	cout<<"Last Occurence Of element "<<key<<" is "<<lastsearch(arr,0,n-1,key);
    }
    return 0;
}