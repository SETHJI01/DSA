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
void threeWayPartition(int array[],int a, int b,int n){
    // code here
    int l=0,r=n-1;
    while(l<r){
        while(l<n-1&&array[l]<a){
            l++;
        }
        while(r>0&&array[r]>b){
            r--;
        }
        if(array[l]>array[r]&&l<r){
            swap(array[l],array[r]);
        }
    }
}
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int n,a,b;
    cin>>n;
    int arr[n];
   	for(int i=0;i<n;i++){
   		cin>>arr[i];
   	}
   	cin>>a>>b;
   	threeWayPartition(arr,a,b,n);
   	fin cout<<arr[i]<<" ";
    return 0;
}
