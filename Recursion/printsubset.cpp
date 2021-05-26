#include<bits/stdc++.h>
using namespace std;
void subset(string str,string curr="",int index=0){
    if(index==str.length()){
        cout<<curr<<endl;
        return;
    }
    subset(str,curr,index+1);
    subset(str,curr+str[index],index+1);
}
int main(){
    string str="ABC";
    subset(str);
    return 0;
}
