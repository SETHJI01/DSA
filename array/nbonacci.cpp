#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,k;
	cin>>n>>k;
	int arr[n];
	for(int i=0;i<k-1;i++){
		arr[i]=0;
	}
	arr[k-1]=1; 	
	arr[k]=1;
	int sum=2;					
	for(int i=k+1;i<n;i++){
		arr[i]=sum-arr[i-k-1];
		sum+=arr[i]-arr[i-k-1];
	}
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
}
