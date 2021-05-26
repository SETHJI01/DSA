#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int L[n],R[n];
	for(int i=0;i<n;i++)
		cin>>L[i];
	for(int i=0;i<n;i++)
		cin>>R[i];
//    for(int i=0;i<=n;i++){
//        v[L[i]]++;
//        v[R[i]+1]--;
//    }
//    int index,max=v[0];
//    for(int i=1;i<=n;i++){
//        v[i]+=v[i-1];
//        if(max<v[i]){
//            max=v[i];
//            index=i;
//        }
	vector<int> v(1000);
    for(int i=0;i<n;i++){
        v[L[i]]++;
        v[R[i]+1]--;
    }
    int index,max=v[0];
    for(int i=1;i<=n;i++){
        v[i]+=v[i-1];
        if(max<v[i]){
            max=v[i];
            index=i;
        }
    }
    cout<<index<<" "<<max;
}
