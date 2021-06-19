#include<bits/stdc++.h>
using namespace std;
void prints(string s,string ans){
    if(s.size()==0){
        cout << ans << " ";
        return;
    }
    for (int i = 0; i < s.size();i++){
        string st = s.substr(0, i) + s.substr(i + 1, s.size());
        prints(st, ans + s[i]);
    }
}
int main(){
    string s,ans="";
    cin >> s;
    prints(s, ans);
}