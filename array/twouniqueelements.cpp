//finding 2 unique element in an array
#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int a[n];
	int x;
	int a1=0,a2=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(i==0)
			x=a[i];
		else
			x=x^a[i];
	}
	//getting the last most set bit kyuki wo set tbhi hui hogi jb dono ki us position wali bit different hongi
	int right_last_setbit = x & ~(x-1);
	for(int i=0;i<n;i++){
		if(a[i]&right_last_setbit)
			a1= a1^a[i];
		else
			a2=a2^a[i];
	}
	cout<<a1<<" "<<a2<<endl;	
}
