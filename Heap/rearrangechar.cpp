#include<bits/stdc++.h>
using namespace std;
int main(){
    string s="aaabc";
    unordered_map<char, int> mp;
    for (int i = 0; i < s.length();i++){
        mp[s[i]]++;
    }
    priority_queue<pair<int, char> > pq;
    for( auto x: mp){
        pq.push({x.second, x.first});
    }
    string str = "";
    pair<int, char>p,prev = {-1, '$'};
    while (!pq.empty()){
        p = pq.top();
        pq.pop();
        str += p.second;
        p.first--;
        if(prev.first>0)
            pq.push(prev);
        prev = p;
    }
    cout << str << endl;
}