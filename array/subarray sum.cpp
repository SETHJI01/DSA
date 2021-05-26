#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,k;
	cin>>n>>k;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int sum=0,start=0,end=0;
	for(int i=0;i<n;i++){
		if(sum==k)
			break;
		while(i<n&&sum<k){
			sum+=arr[i];
			i++;
			end++;	
		}
		while(start<n&&sum>k){
			sum-=arr[start++];
		}
	}
	for(int i=start;i<end;i++){
		cout<<arr[i]<<" ";
	}
}
