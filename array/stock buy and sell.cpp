#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,i;
	cin>>n;
	vector<int> v;
	for( i=0;i<n;i++){
		int val;
		cin>>val;
		v.push_back(val);
	}
	i=0;
	int s,e;
	while(i<n-1 && v[i]>=v[i+1] ){
		i++;
	}
	vector<pair<int,int> >list;
	int count=0;							//100,180,260,310,40,535,695
	if(i==n-1)
		cout<<0<<endl;
	else{
	while(i<n-1){
		s=i;
		while(i<n-1 && v[i]<=v[i+1])
			i++;
		e=i;
		list.push_back({s,e});
		i++;
	}
}
	for(int i=0;i<list.size();i++){
		cout<<list[i].first<<" "<<list[i].second<<endl;
	}
	
}
