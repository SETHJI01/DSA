//KMP algorithm for LPS
#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin>>s;
	int lps[s.length()];
	lps[0]=0;
	int len=0;
	int i=1;
	while(i<s.length()){
		if(s[i]==s[len])
			len++,lps[i]=len,i++;
		else{
			if(len==0)
				lps[i]=0,i++;
			else
				len=lps[len-1];
		}
	}
	cout<<lps[s.length()-1];
}
