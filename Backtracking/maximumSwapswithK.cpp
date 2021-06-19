#include<bits/stdc++.h>
using namespace std;
void findMaximum(string str,int k,string &max){
    if(str.compare(max)>0)
        max = str;
    if(k==0)
        return;
    for (int i = 0; i < str.size() - 1;i++){
        for (int j = i+1; j < str.size();j++){
            if(str[i]<str[j]){
                swap(str[i], str[j]);
                findMaximum(str, k-1, max);
                swap(str[i], str[j]);
            }
        }
    }
}
int main(){
    string s;
    cin >> s;
    int k;
    cin >> k;
    string max = s;
    findMaximum(s, k, max);
    cout << max << endl;
}