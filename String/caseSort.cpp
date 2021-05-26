#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    int n=s.length();
    int hash_sm[26]={0},hash_cap[26]={0};
    for(int i=0;i<n;i++){
        if(s[i]>='A'&&s[i]<='Z')
            hash_cap[s[i]-'A']++;
        else
            hash_sm[s[i]-'a']++;
    }
    int sm=0,cap=0;
    string str="";
    for(int i=0;i<n;i++){
        if(s[i]>='A'&&s[i]<='Z'){
            while(hash_cap[cap]==0&&cap<26){
                cap++;
            }
            char temp='A'+cap;
            str+=temp;
            hash_cap[cap]--;
        }
        else{
            while(hash_sm[sm]==0&&sm<26){
                sm++;
            }
            char temp='A'+sm;
            str+=temp;
            hash_sm[sm]--;
        }
    }
    cout<<str;
}
