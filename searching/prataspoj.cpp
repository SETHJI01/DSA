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
bool isValid(int arr[],int mid,int n,int p){
	int count=0;

	for(int i=0;i<n;i++){
		count+=(-1+ sqrt(1+(4*2*mid)/arr[i]))/2;
	}
	if(count>=p)
		return true;
	else
		return false;
}
int solution(int arr[],int l,int h,int n,int p){
	int ans=0;
	while(l<=h){
		int mid=l + (h-l)/2;
		if(isValid(arr,mid,n,p)){
			ans=mid;
			h=mid-1;
		}
		else
			l=mid+1;
	}
	return ans;
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
    	int n,p,max=0;
    	cin>>p>>n;
    	int arr[n];
    	fin{
    	 	cin>>arr[i];
    	 	if(max<arr[i])
    	 		max=arr[i];
    	}
    	int cal=p*(p+1)/2;
    	cout<<solution(arr,0,max*cal,n,p)<<endl;
    }
    return 0;
}