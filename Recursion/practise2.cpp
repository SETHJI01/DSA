#include <bits/stdc++.h>
#define ll long long int 
#define fin for(int i=0;i<n;i++)
#define ff first
#define ss second
#define vi vector<int>
#define vc vector<char>
#define vii vector<int,int>
using namespace std;
int main() {
    bool prime[1000001];
    memset(prime, true, sizeof(prime));
    for (int p = 2; p * p <= 1000000; p++)
    {
        if (prime[p] == true) 
        {
            for (int i = p * p; i <= 1000000; i += p)
                prime[i] = false;
        }
    }
    vector<int> prime2;
    for (int p = 2; p <= 1000000; p++)
        if (prime[p])
            prime2.push_back(p);
    int count[1000000]={0};
    for(int i=2;i<prime2.size();i++){
        int a=0,b=i-1;
        count[i]=count[i-1];
        while(a<b){
            if(prime2[a]+prime2[b]==prime2[i]){
                count[i]++;
                break;
            }
            else if(prime2[a]+prime2[b]>prime2[i])
                b--;
            else
                break;
        }
    }
    ll t,n;
    cin>>t;
    while(t--){
        cin>>n;
        if(n<5)
			cout<<0<<endl;
        else{
		auto it = lower_bound(prime2.begin(),prime2.end(),n);
        if(prime[n]){}
        else
			it--;
        int c = it - prime2.begin();
        cout<<count[c]<<endl;
    }
    }
}
