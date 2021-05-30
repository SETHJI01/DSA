#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,val;
    cin >> n;
    set<int> s;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        s.insert(val);
        auto it = s.upper_bound(val);
        if (it != s.end())
            v.push_back(*it);
        else
            v.push_back(-1);
    }
    for (int i = 0; i < n;i++)
        cout << v[i] << " ";
}