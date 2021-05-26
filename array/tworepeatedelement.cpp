//element as array index
// if(A[abs(A[i])])<0 that means that the abs(A[i]) is repeated
#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=0;i<n;i++){
		if(a[abs(a[i])]>0) // that means element occuring first time
			a[abs(a[i])]= -a[abs(a[i])]; //making it to negative
		else //that means repeated one
			cout<<abs(a[i])<<endl;
	}
}
