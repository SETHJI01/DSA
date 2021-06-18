#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,cap;
    cin >> n>>cap;
    vector < pair< double, pair<int, int> > > vec;
    for (int i = 0; i < n;i++){
        int w, v;
        cin >> w >> v;
        double vpw = (double)v / (double)w;
        vec.push_back({vpw, {w, v}});
    }
    sort(vec.begin(), vec.end());
    int res = 0;
    int rem = cap;
    for (int i = n-1; i >=0;i--){
        if(vec[i].second.first<=rem){
            rem -= vec[i].second.first;
            res += vec[i].second.second;
        }
        else{
            res += (vec[i].first) * rem;
            rem = 0;
            break;
        }
    }
    cout << res << endl;
}