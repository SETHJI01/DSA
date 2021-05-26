#include<bits/stdc++.h>
using namespace std;
int main(){
    string txt,pat;
    cin>>txt>>pat;
    int hash_pat[256]={0},hash_txt[256]={0};
    int n=txt.length();
    int m=pat.length();
    for(int i=0;i<m;i++){
        hash_pat[pat[i]]++;
    }
    int count=0;
    int len=INT_MAX,start=0,start_index=-1;
    for(int i=0;i<n;i++){
        hash_txt[txt[i]]++;
        if(hash_txt[txt[i]]<=hash_pat[txt[i]])
            count++;
        if(count==m){
            while((hash_txt[txt[start]]>hash_pat[txt[start]])||hash_pat[txt[start]]==0){
                if(hash_txt[txt[start]]>hash_pat[txt[start]])
                    hash_txt[txt[start]]--;
                start++;
            }
            int len_window=i-start+1;
            if(len>len_window){
                len=len_window;
                start_index=start;
            }
        }
    }
    if(start_index==-1)
        cout<<"No such window is present"<<endl;
    else
        cout<<txt.substr(start_index,len)<<endl;
    return 0;
}
