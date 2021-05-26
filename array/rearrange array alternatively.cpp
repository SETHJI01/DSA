#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int k=0;
	int i=n-1;
	while(k<i){
		int temp=arr[n-1];
		int j=i;
		while(j>k){
			arr[j]=arr[j-1];
			j--;
		}
		arr[j]=temp;
		k+=2;
	}
	for( i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
}
