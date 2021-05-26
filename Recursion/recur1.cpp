#include<iostream>
using namespace std;
// void print(int n){
//     if(n<1)
//         return;
//     cout<<n<<" ";
//     print(n-1);
// }
void print2(int n){
    if(n<1)
        return;
    print2(n-1);
    cout<<n<<" ";
}
int main(){
    print2(5);
}