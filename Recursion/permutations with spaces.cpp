#include<bits/stdc++.h>
using namespace std;
void print(string s,string o,int size){
    if(size==s.size()){
        cout<<o<<endl;
        return;
    }
    if(size==0){
        print(s,o+s[size],size+1);
    }
    else{
        print(s,o+" "+s[size],size+1);
        print(s,o+s[size],size+1);
    }
}
int main(){
    string s="ABC";
    print(s,"",0);
}
