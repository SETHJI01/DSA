#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int MAX=arr[n-1]+1;
	int min_index=0;
	int max_index=n-1;
	for(int i=0;i<n;i++){
		if(i%2==0)
			arr[i]=(arr[max_index--]%MAX)*MAX+arr[i];
		else
			arr[i]=(arr[min_index++]%MAX)*MAX+arr[i];
	}
	for(int i=0;i<n;i++){
		arr[i]=arr[i]/MAX;
		cout<<arr[i]<<" ";
	}	
}
