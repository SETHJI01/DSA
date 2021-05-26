// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution{
    public:
    int subArraySum(int arr[], int n, int sum)
    {
        //Your code here
        int i,j,count=0,presum=0;
    unordered_map<int,int>s;
    s[0]++;
    for(i=0;i<n;i++)
    {
        presum+=arr[i];
        auto it=s.find(presum-sum);
        if(it!=s.end())
        {
        	cout<<count<<" "<<s[presum]<<" "<<presum<<endl;
            count+=it->second;
        }
        s[presum]++;
    }
    return count;
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n,sum=0;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    cin>>arr[i];
	    cin>>sum;
	    Solution obj;
	    cout<<obj.subArraySum(arr, n, sum)<<endl;
	}
	return 0;
}  // } Driver Code Ends
