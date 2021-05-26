//reversing the words in a string using stack
#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	getline(cin,s);
	stack<string> st;
	string t="";
	for(int i=0;i<s.length();i++){
		if(s[i]==' '){
			st.push(t);
			t="";
		}
		if(i==s.length()-1){
			t+=s[i];
			st.push(t);
		}
		else
			t+=s[i];
	}
	t="";
	while(st.size()){
		t+=st.top();
		st.pop();
	}
	cout<<t<<endl;
}
