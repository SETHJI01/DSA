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
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int n;
    cin>>n;
    int arr[n];
    fin cin>>arr[i];
    int sum[n];
    sum[0]=arr[0];
    int max=arr[0],min=arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]==1)
            sum[i]=sum[i-1]+arr[i];
        else
            sum[i]=sum[i-1]-1;
        if(max<sum[i])
            max=sum[i];
        if(min>sum[i])
            min=sum[i];
    }
    int hash[max-min+1];
    for(int i=0;i<max-min+1;i++)
        hash[i]=-1;
    int size=INT_MIN;
    for(int i=0;i<n;i++){
        if(hash[sum[i]-min]==-1){
            hash[sum[i]-min]=i;
            cout<<sum[i]<<" "<<i<<endl;
        }
        else{
            int x=i-hash[sum[i]-min];
            if(x>size)
                size=x;
        }
    }
    cout<<size<<endl;
    return 0;
}