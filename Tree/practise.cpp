#pragma GCC optimize("Ofast","unroll-loops")
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long long
#define pii pair<int,int>
template<typename T>
using Prior = std::priority_queue<T>;
template<typename T>
using prior= std::priority_queue<T,vector<T>,greater<T>>;
#define eb emplace_back
#define ALL(child) begin(child),end(child)
#define RALL(child) rbegin(child), rend(child)
#define fastIO() ios_base::sync_with_stdio(0),cin.tie(0)

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

inline int getRand(int L,int R){
    if(L>R) swap(L,R);
    return(int)(rng()%(uint64_t)(R-L+1)+L);
}
template<typename T1,typename T2>
ostream& operator<<(ostream &os,pair<T1,T2>p){
    os<<"("<<p.first<<","<<p.second<<")";
    return os;
}
template<typename T>
ostream&operator<<(ostream &os,vector<T>vec){
    for(int i=0;i<vec.size();++i){
        if(i)os<<"";
        os<<vec[i];
    }
    return os;
}
vector<int> adj[MAXN],v1,v2;
vector<pii>vec;
const int MAXN=3E5+5;
const int mod=1E9+7;
void dfs(int curr,int prev=-1){
    for(auto child:adj[curr]){
        if(child==prev)
            continue;
        dfs(child,curr);
    }
    vec.clear();{
        for(auto child:adj[curr]){
            if(child!=prev)
            vec.eb(v1[child],child);
        }
        sort(RALL(vec));
        
        int tok=1;
        for(auto [_v2,id]:vec)
            v2[id]=tok++;
        for(auto child:adj[curr]){
            if(child!=prev)
                v1[curr]+=v2[child]*v1[child];
        }
    }
}
int32_t main(){
    fastIO();
    
    int t;
    cin>>t;
    while(t--){
        int N,X;
        cin>>N>>X;
        v1.assign(N, 1);
        v2.assign(N, 0);
        for(int i=0;i<N;i++)
            vector<int>().swap(adj[i]);
        for(int i=0;i<N-1;++i)
        {
            int u,v;
            cin >> u >> v;
            u--, v--;
            adj[u].eb(v),adj[v].eb(u);
        }
        dfs(0);
        cout<<v1[0]%mod*X%mod<<"\n";
    }
    return 0;
}