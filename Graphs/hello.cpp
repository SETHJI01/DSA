#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define fl(a,b) for(int i=a;i<b;i++)
#define ff first
#define ss second
#define pb push_back
#define ppb pop_back
#define vi vector<int>
#define vc vector<char>
#define pii pair<int,int>
#define vii vector< pair<int,int> >
#ifndef ONLINE_JUDGE
#define debug(x)cerr << #x <<" "; _print(x); cerr<<endl;
#else
#define debug(x)
#endif

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(double t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

int main(){
    fastio();
    ll t;
    cin>>t;
    while(t--){
        int n,l,r;
        cin>>n>>l>>r;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        sort(arr,arr+n);
        int left=0;
        int right=n-1;
        int count=0;
        while(left<right){
            int ans=arr[left]+arr[right];
            if(ans<l)
                left++;
            if(ans>r)
                right++;
            else{
                count++;
            }
        }
        cout<<count<<endl;
    }
    return 0;
}