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
void merge(int arr[],int l,int mid,int h){
	int n1=mid-l+1,n2=h-mid;
	int right[n2],left[n1];
	for(int i=0;i<n1;i++)
		left[i]=arr[i+l];
	for(int i=0;i<n2;i++)
		right[i]=arr[mid+i+1];
	int i=0,j=0,k=l;
	while(i<n1&&j<n2){
		if(left[i]>right[j]){
			arr[k++]=right[j++];
		}
		else
			arr[k++]=left[i++];
	}
	while(i<n1)
		arr[k++]=left[i++];
	while(j<n2){
		arr[k++]=right[j++];
	}
}
void mergeSort(int arr[],int l,int h){
	if(l==h)
		return;
	int mid=l+(h-l)/2;
	mergeSort(arr,l,mid);
	mergeSort(arr,mid+1,h);
	merge(arr,l,mid,h);
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
    mergeSort(arr,0,n-1);
    fin cout<<arr[i]<<" ";
    return 0;
}