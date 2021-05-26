// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


// arr: input array
// num: length of array
// This function returns true or false
bool checkRotatedAndSorted(int arr[], int n){
    // Your code here
    int count=0;
	for(int i=1;i<n;i++){
		while(i<n&&arr[i-1]<arr[i])
			i++;
		count++;
		if(count>2){
			break;
		}
	}
	count-=1;
	if(count==1){
		return true;
		
	}
	else{
	    count=0;
	    for(int i=1;i<n;i++){
		while(i<n&&arr[i-1]>arr[i])
			i++;
		count++;
		if(count>2){
			break;
		}
	}
	if(count==n-1)
		return false;
	count-=1;
	if(count==1){
		return true;
	}
	else{
	    return false;
	}
    }
}

// { Driver Code Starts.

int main()
 {
	int T;
	//testcases
	cin>> T;
	
	while (T--){
	    int num;
	    //size of array
        cin>>num;
        int arr[num];
        
        //inserting elements
        for(int i = 0; i<num; ++i)
            cin>>arr[i];
        
        bool flag = false;
        
        //function call
        flag = checkRotatedAndSorted(arr, num);
        
        //printing "No" if not sorted and
        //rotated else "Yes"
        if(!flag){
            cout << "No"<<endl;
        }
        else
        cout << "Yes"<<endl;
    
	}
	
	return 0;
}  // } Driver Code Ends
