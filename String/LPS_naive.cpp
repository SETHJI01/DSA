//longest proper prefix which is also a suffix
//naive method O(n^3)
#include<bits/stdc++.h>
using namespace std;
int solution(string s,int n){
	for(int len=n-1;len>=0;len--){
		bool flag=true;
		for(int j=0;j<len;j++){
			if(s[j]!=s[n-len+j])
				flag=false;
		}
		if(flag)
			return len;
	}
	return 0;
}
int main(){
	string s;
	cin>>s;
	int ans[s.length()];
	for(int i=0;i<s.length();i++){
		ans[i]=solution(s,i+1);
	}
	for(int i=0;i<s.length();i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
