#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int a[n+2];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(a[i]>0&&a[i]!=i&&i<=n){
			swap(a[i],a[a[i]]);
			i--;
		}
	}
	bool check=false;
	for(int i=1;i<=n;i++){
		if(a[i]!=i){
			check=true;
			cout<<i<<endl;
		}
	}
	if(check==false)
		cout<<n+1<<endl;
	
}
