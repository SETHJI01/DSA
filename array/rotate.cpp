#include<bits/stdc++.h>
using namespace std;
void reverse(int a[],int n){
	for(int i=0;i<n;i++){
		if(i<n-i-1)
			swap(a[i],a[n-i-1]);
		else
			break;
	}
}
int main(){
	int arr[]={1,2,3,4,5};
	int k;
	cin>>k;
	reverse(arr+5-k,k);
	reverse(arr,5-k);
	reverse(arr,5);
	for(int i=0;i<5;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}
