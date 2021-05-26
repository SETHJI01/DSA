//best efficient
//use bool array to check visited
//start from right and mark visited if already visited then store the recent index
//since we are using it from right then the leftmost index get stored automatically

#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin>>s;
	vector<bool> v(26);
	int ans;
	for(int i=s.length()-1;i>=0;i--){
		if(!v[s[i]-'a'])
			v[s[i]-'a']=true;
		else
			ans=i;
	}
	cout<<ans<<endl;
}
