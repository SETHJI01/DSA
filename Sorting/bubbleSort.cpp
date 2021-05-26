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
void bubbleSort(int arr[],int n){
	for(int i=0;i<n;i++){
		for(int j=1;j<n-i;j++){
			if(arr[j-1]>arr[j])
				swap(arr[j-1],arr[j]);
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
    int n;
    cin>>n;
    int arr[n];
    fin cin>>arr[i];
    bubbleSort(arr,n);
    fin cout<<arr[i]<<" ";
    return 0;
}