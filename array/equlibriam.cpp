#include<bits/stdc++.h>
using  namespace std;
int main(){
	int n;
	cin>>n;
	int arr[n],prefsum[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
		if(i==0)
			prefsum[i]=arr[i];
		else
			prefsum[i]=prefsum[i-1]+arr[i];
	}
	for(int i=0;i<n;i++){
		if(prefsum[i]-arr[i]==prefsum[n-1]-prefsum[i]){
			cout<<i<<endl;
			break;
		}
	}
	return 0;
}
