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
	int arr[]={1,2,3,4,5,6,7,8,9};
	reverse(arr,9);
	for(int i=0;i<9;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}
