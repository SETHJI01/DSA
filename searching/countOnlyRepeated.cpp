#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define fin for(int i=0;i<n;i++)
#define ff first
#define ss second
#define vi vector<int>
#define vc vector<char>
#define vii vector<int,int>
#define pb push_back
#define mp make_pair
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int t;
    cin>>t;
    while(t--){
    	int n;
    	cin>>n;
    	int arr[n];
    	fin cin>>arr[i];
    	for(int i=0;i<n-1;i++){
    		if(arr[i]==arr[i+1]){
    			int start=i,end=i+1;
    			while(arr[end]==arr[start]){
    				end++;
    			}
    			cout<<arr[start]<<" "<<end-start<<endl;
    			break;
    		}
    	}
    }
    return 0;
}