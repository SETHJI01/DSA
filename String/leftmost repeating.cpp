#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin>>s;
	vector<int> v(26,-1);
	int ans=INT_MAX;
	for(int i=0;i<s.length();i++){
		if(v[s[i]-'a']==-1)
			v[s[i]-'a']=i;
		else
			if(v[s[i]-'a']<ans)
				ans=v[s[i]-'a'];	
	}
	cout<<ans<<endl;
}
