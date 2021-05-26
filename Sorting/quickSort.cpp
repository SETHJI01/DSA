#include <bits/stdc++.h>
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
void quickSort(int arr[],int l,int r){
	if(l<r){
		int i=l+1,j=r;
		int pivot=arr[l];
		while(i<j){
			while(arr[i]<=pivot&&i<r)
				i++;
			while(arr[j]>=pivot&&j>l)
				j--;
			if(i<j&&arr[i]<arr[j]){
				swap(arr[i],arr[j]);
			}
		}
		if(arr[l]>arr[j])
			swap(arr[l],arr[j]);
		quickSort(arr,l,j-1);
		quickSort(arr,j+1,r);
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
    quickSort(arr,0,n-1);
    fin cout<<arr[i]<<" ";
    return 0;
}