#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,k;
	cin>>n>>k;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int currsum=0;
	for(int i=0;i<k;i++){
		currsum+=arr[i];
	}
	int maxwsum=currsum;
	int minwsum=currsum;
	for(int i=k;i<n;i++){
		currsum+=arr[i]-arr[i-k];
		if(currsum>maxwsum)
			maxwsum=currsum;
		if(currsum<minwsum)
			minwsum=currsum;		
	}
	cout<<maxwsum<<" "<<minwsum<<endl;
}
