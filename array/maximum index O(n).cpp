#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int Lmin[n],Rmax[n];
	Lmin[0]=arr[0];
	for(int i=1;i<n;i++)
		Lmin[i]=min(Lmin[i-1],arr[i]);
	Rmax[n-1]=arr[n-1];
	for(int i=n-2;i>=0;i--)
		Rmax[i]=max(Rmax[i+1],arr[i]);
	int i=0,j=0,ans=-1;
	while(i<n&&j<n){
		if(Lmin[i]<Rmax[j]){
			ans=max(ans,j-i);
			j++;
		}
		else
			i++;
	}
	cout<<ans;
}
