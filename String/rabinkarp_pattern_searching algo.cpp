#include<bits/stdc++.h>
using namespace std;
int main(){
	string s1,s2;
	cin>>s1>>s2;
	int d=256,q=101;
	int m=s2.length(),n=s1.length(),h=1;
	for(int i=1;i<=m-1;i++)
		h=(h*d)%q;
	int p=0,t=0;
	for(int i=0;i<m;i++){
		p=(p*d+s2[i])%q;
		t=(t*d+s1[i])%q;
	}
	for(int i=0;i<=n-m;i++){
		if(t==p){
			bool flag=true;
			for(int j=0;j<m;j++){
				if(s1[i+j]!=s2[j]){
					flag=false;
				}
			}
			if(flag)
				cout<<i<<" ";
		}
		if(i<n-m){
			t=((d*(t-s1[i]*h))+s1[i+m])%q;
		}
		if(t<0)	t=t+q;
	}
}
