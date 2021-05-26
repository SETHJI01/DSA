// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


// Function to find the maximum difference of j-i
// arr[]: input array
// n: size of array
int maxIndexDiff(int arr[], int n) 
{ 
    
    // Your code her
    int ans=0;
    for(int i=0;i<n;i++){
    	    int j=n-1;
    	while(j>i&&arr[j]<arr[i]){
    		j--;
		}
		if(arr[j]>arr[i]){
			int x=j-i;
			if(ans<x)
				ans=x;
		}
	}
	return ans;
}

// { Driver Code Starts.
  
/* Driver program to test above functions */
int main() 
{
    int T;
    //testcases
    cin>>T;
    while(T--){
        int num;
        //size of array
        cin>>num;
        int arr[num];
        
        //inserting elements
        for (int i = 0; i<num; i++)
            cin>>arr[i];
        
        //calling maxIndexDiff() function
        cout<<maxIndexDiff(arr, num)<<endl;    
        
    }
    return 0;
}   // } Driver Code Ends
