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
bool isValid(vector<int>& bloomDay, int mid,int m, int k){
        int count=0;
        for(int i=0;i<bloomDay.size();i++){
            bool check=true;
            int t=0;
            for(int j=i;j<i+k;j++){
            	t++;
                if(j>=bloomDay.size()||bloomDay[j]>mid){
                    check=false;
                    break;
                }
            }
            i=i+t-1;
            if(check){
                count+=1;
            }
            if(count>=m){
                return true;
            }
        }
        return false;
    }
    int solve(vector<int>& bloomDay, int l,int h,int m, int k){
        int res=-1;
        while(l<=h){
            int mid= l + (h-l)/2;
            if(isValid(bloomDay,mid,m,k)){
                res=mid;
                h=mid-1;
            }
            else
                l=mid+1;
        }
        return res;
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
    	int n,m,k;
    	cin>>n;
    	int min=INT_MAX,max=INT_MIN;
    	vector<int> arr(n);
    	fin {
    		cin>>arr[i];
    		if(arr[i]>max)
                max=arr[i];
            if(arr[i]<min)
                min=arr[i];
    	}
    	cin>>m>>k;
    	if(n<m*k)
    		cout<<-1<<endl;
    	else
    		cout<<solve(arr,min,max,m,k)<<endl;
    }
    return 0;
}