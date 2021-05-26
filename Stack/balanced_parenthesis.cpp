#include<bits/stdc++.h>
using namespace std;
bool open(char c){
    if(c=='{'||c=='['||c=='(')
        return true;
    return false;
}
bool match(char st,char s){
    if((st=='('&&s==')')||(st=='{'&&s=='}')||(st=='['&&s==']'))
        return true;
    return false;
}
bool check(string s){
    stack<char> st;
    for (int i = 0; i < s.size(); i++){
        if(open(s[i]))
            st.push(s[i]);
        else{
            if(st.empty()==true)
                return false;
            else if(match(st.top(),s[i])==false)
                return false;
            else
                st.pop();
        }
    }
    if(st.empty()==true)
        return true;
    return false;
}
int main(){
    string s;
    cin >> s;
    if(check(s))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}