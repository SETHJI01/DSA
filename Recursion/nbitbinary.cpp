#include<bits/stdc++.h>
using namespace std;
void print(int o,int z,int n,string s){
	if(n==0){
		cout<<s<<endl;
		return;
	}
	if(o==z){
		print(o+1,z,n-1,s+"1");
	}
	else if(o>z){
		print(o+1,z,n-1,s+"1");
		print(o,z+1,n-1,s+"0");
	}
}
int main(){
	int n,o=0,z=0;
	cin>>n;
	print(o,z,n,"");
}
