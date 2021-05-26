#include<bits/stdc++.h>
using namespace std;
bool check(string str,int s,int e){
    if(s==e)
        return true;
    if(str[s]!=str[e])
        return false;
    if(s<e)
        return check(str,s+1,e-1);
    else
        return true;
}
int main(){
    string s;
    cin>>s;
    int n=s.length()-1;
    if(check(s,0,n))
        cout<<"Palindrome"<<endl;
    else
        cout<<"Not palindrome"<<endl;
}

