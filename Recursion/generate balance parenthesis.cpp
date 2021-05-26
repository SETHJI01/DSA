#include<bits/stdc++.h>
using namespace std;
void print(int o,int c,string s){
    if(o==0&&c==0){
        cout<<s<<endl;
        return;
    }
    if(o==c){
        print(o-1,c,s+"(");
    }
    else{
        if(o>0)
            print(o-1,c,s+"(");
        if(c>0)
            print(o,c-1,s+")");
    }
}
int main(){
    int n,o,c;
    cin>>n;
    o=n,c=n;
    print(o,c,"");
}
