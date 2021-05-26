//longest substring having distinct characters
#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin>>s;
	int arr[26]={0};
	int len=INT_MIN;
	for(int i=0;i<s.length();i++){
		if(arr[s[i]-'a']!=0){
			if(len<i)
				len=i;
			arr[s[i]-'a']=1;
		}
		else
			arr[s[i]-'a']++;
	}
	cout<<len;
}
