#include<bits/stdc++.h>
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
char nextletter(char arr[],int b l,int h,char key){
	while(l<=h){
		int mid=l+(h-l)/2;
		if(arr[mid]<=key&&arr[mid+1]>key)
			return arr[mid+1];
		else if(arr[mid]<key)
			l=mid+1;
		else
			h=mid-1;
	}
	return -1;
}
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
    	char arr[n];
    	fin cin>>arr[i];
    	char key;
    	cin>>key;
    	if(arr[0]==key)
    		cout<<arr[1]<<endl;
    	else if(arr[n-1]==key||n==1)
    			cout<<-1<<endl;
    	else
    		cout<<nextletter(arr,0,n-1,key);
    }
    return 0;
}