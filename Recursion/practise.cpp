// { Driver Code Starts
//Initial function template for C++

#include <bits/stdc++.h>
using namespace std;
int x;
int lowerbound(int arr[],int l,int h,int key=-1){
    if(l<=h){
        int mid= l + (h-l)/2;
        if(mid>0&&arr[mid]==arr[mid-1]){
            cout<<1<<" "<<mid<<" "<<arr[mid]<<endl;
			key=arr[mid];
        }
        if(mid<h-1&&arr[mid]==arr[mid+1]){
        	cout<<2<<" "<<mid<<" "<<arr[mid]<<endl;
            key=arr[mid];
        }
        if(mid>0&&arr[mid]==arr[mid-1]){
            cout<<3<<" "<<mid<<" "<<arr[mid]<<endl;
			return lowerbound(arr,l,mid-1,key);
        }
        else if(key>=0&&arr[mid]!=arr[mid-1]&&arr[mid]==key){
            cout<<4<<" "<<mid<<" "<<arr[mid]<<endl;
            x=mid;
            cout<<x<<endl;
			return arr[mid];            
        }
        else if(mid>arr[mid]-1){
        	cout<<5<<" "<<mid<<" "<<arr[mid]<<endl;
            return lowerbound(arr,l,mid-1);
        }
        cout<<6<<" "<<mid<<" "<<arr[mid]<<endl;
        return lowerbound(arr,mid+1,h);
    }
}
int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    int n;
	    cin >> n;
	    int arr[n];
	    
	    for(int i = 0;i<n;i++){
	        cin >> arr[i];
	    }
	    
//	    pair<int, int> ans = findRepeating(arr,n);
	    cout<<lowerbound(arr,0,n-1)<<endl;
		cout<<x<<endl;
	}
	
}// } Driver Code Ends


//User function template for C++

// arr : given array
// n : size of the array

//pair<int, int> findRepeating(int *arr, int n){
//    //code here
//    
//}
