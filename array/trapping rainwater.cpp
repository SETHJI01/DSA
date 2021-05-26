// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


 // } Driver Code Ends


   

// function to find the trapped water in between buildings
// arr: input array
// n: size of array
int trappingWater(int arr[], int n){
   int leftmax[n],rightmax[n];
	for(int i=0;i<n;i++){
		if(i==0)
			leftmax[i]=arr[i];
		else
			leftmax[i]=max(arr[i],leftmax[i-1]);
	}
	for(int i=n-1;i>=0;i--){
		if(i==n-1)
			rightmax[i]=arr[i];
		else
			rightmax[i]=max(arr[i],rightmax[i+1]);
	}
	int ans=0;
	for(int i=0;i<n;i++){
		ans+=min(rightmax[i],leftmax[i])-arr[i];
	}
    return ans;
}

// { Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        
        //calling trappingWater() function
        cout << trappingWater(a, n) << endl;
        
    }
    
    return 0;
}  // } Driver Code Ends
