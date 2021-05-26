#include<bits/stdc++.h>
using namespace std;
void print(string s,string o,int size){
    if(size==s.size()){
        cout<<o<<endl;
        return;
    }
    print(s,o+s[size],size+1);
    if(s[size]>='A'&&s[size]<='Z'){
        char n=s[size]+32;
        print(s,o+n,size+1);
    }
    else{
        char n=s[size]-32;
        print(s,o+n,size+1);
    }
}
int main(){
    string s="ABC";
    print(s,"",0);
}
