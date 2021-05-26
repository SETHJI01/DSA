// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// #define fin for(int i=0;i<n;i++)
// #define ff first
// #define ss second
// #define pb push_back
// #define ppb pop_back
// #define vi vector<int>
// #define vc vector<char>
// #define vii vector< pair<int,int> >
// void nthprimedigitsnumber(long long n){
// 	int prev_count=0,len=1;
// 	while(1){
// 		long long curr_count=prev_count + 4*pow(4,len-1);
// 		if(prev_count<n && curr_count>=n)
// 			break;
// 		len++;

// 		prev_count=curr_count;
// 	}
// 	for(int i=1;i<=len;i++){
// 		for(int j=1;j<=4;j++){
// 			if(prev_count+pow(4,len-i)<n)
// 				prev_count+=pow(4,len-i);
// 			else{
// 				if(j==1)
// 					cout<<"2";
// 				if(j==2)
// 					cout<<"3";
// 				if(j==3)
// 					cout<<"5";
// 				if(j==4)
// 					cout<<"7";
// 				break;
// 			}
// 		}
// 	}
// 	cout<<endl;
// }
// int main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     #ifndef ONLINE_JUDGE
//         freopen("input.txt","r",stdin);
//         freopen("output.txt","w",stdout);
//     #endif
//     int n;
//     cin>>n;
//     nthprimedigitsnumber(n);
//     return 0;
// }
#include <algorithm> 
#include <iostream> 
#include <string> 
using namespace std; 
  
string nthprimedigitsnumber(int number) 
{ 
    int rem; 
    string num; 
    while (number) { 
        // remainder for check element position 
        rem = number % 4; 
        switch (rem) { 
  
        // if number is 1st position in tree 
        case 1: 
            num.push_back('2'); 
            break; 
  
        // if number is 2nd position in tree 
        case 2: 
            num.push_back('3'); 
            break; 
  
        // if number is 3rd position in tree 
        case 3: 
            num.push_back('5'); 
            break; 
  
        // if number is 4th position in tree 
        case 0: 
            num.push_back('7'); 
            break; 
        } 
  		// to fall it under the previous catagories of the next digit
        if (number % 4 == 0) 
           number--; 
  
        number = number / 4; 
    } 
    reverse(num.begin(), num.end()); 
    return num; 
} 
  
// Driver code 
int main() 
{ 
    int number = 21; 
    cout << nthprimedigitsnumber(12) << "\n"; 
    cout << nthprimedigitsnumber(21) << "\n"; 
    return 0; 
} 