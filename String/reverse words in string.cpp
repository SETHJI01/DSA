//reversing words in a string using my method
#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	getline(cin,s);
	reverse(s.begin(),s.end());
	int x=0;
	for(int i=0;i<s.length();i++){
		if(s[i]==' '){
			reverse(s.begin()+x,s.begin()+i);
			x=i+1;
		}
		if(i==s.length()-1){
			reverse(s.begin()+x,s.begin()+i+1);
		}
	}
	cout<<s<<endl;
}
