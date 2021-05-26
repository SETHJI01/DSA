#include<bits/stdc++.h>
using namespace std;
void subset(string s,string o,int size,set<string> &st){
    if(size==s.size()){
        st.insert(o);
        return;
    }
    subset(s,o,size+1,st);
    subset(s,o+s[size],size+1,st);
}
int main(){
    string s="aab";
    set<string> st;
    subset(s,"",0,st);
    for(auto it=st.begin();it!=st.end();it++ ){
        cout<<*it<<endl;
    }
    return 0;
}
