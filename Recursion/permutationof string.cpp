#include<bits/stdc++.h>
using namespace std;
void print(string s,int l,int r){
	if(l==r){
		cout<<s<<endl;
	}
	else{
		for(int i=l;i<=r;i++){
			swap(s[l],s[i]);
			print(s,l+1,r);
			swap(s[l],s[i]);
		}
	}
}
int main(){
	string s="ABC";
	print(s,0,s.length()-1);
	return 0;
}
