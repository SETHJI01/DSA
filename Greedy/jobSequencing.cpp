#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<pair<int, int>> v;
    int mb = 0;
    for (int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        v.push_back({b, a});
        if(mb<b){
            b = mb;
        }
    }
    sort(v.begin(), v.end());
    unordered_map<int, int> mp;
    int ans = 0;
    for (int i = n-1; i>=0; i--){
        if(mp[v[i].second]){}
        else{
            mp[v[i].second] = v[i].first;
            ans += v[i].first;
        }
    }
    cout << ans << endl;
}