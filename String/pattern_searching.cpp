//pattern searching in string
#include<bits/stdc++.h>
using namespace std;
int main(){
	string s1,s2;
	cin>>s1>>s2;
	int x=0;
	vector<int> v;
	int ans=0;
	for(int i=0;i<s1.length();i++){
		if(x==s2.length()){
			v.push_back(ans);
			x=0;
			i--; 
		}
		else if(s1[i]==s2[x]){
			if(x==0)
				ans=i;
			x+=1;
		}
		else if(x>0&&s1[i]!=s2[x]&&x!=s2.length()){
			i=i-x;
			x=0;
		}
		else
			x=0;
	}
	if(x==s2.length())
		v.push_back(ans);
	for(int i=0;i<v.size();i++)
		cout<<v[i]<<" ";
}
