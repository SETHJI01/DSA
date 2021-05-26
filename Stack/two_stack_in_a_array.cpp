#include<bits/stdc++.h>
using namespace std;
int arr[100];
int top1 = -1, top2 = 100;
void push1(int key){
    if(top2==top1+1)
        cout << "Stack FULL" << endl;
    arr[++top1] = key;
}
void push2(int key){
    if(top2==top1+1)
        cout << "Stack FULL" << endl;
    arr[--top2] = key;
}
int pop1(){
    if(top1==-1)
        return -1;
    return arr[top1--];
}
int pop2(){
    if(top2==100)
        return -1;
    return arr[top2--];
}
int main(){
    push1(10);
    push1(20);
    push1(130);

    push2(1);
    push2(2);
    push2(3);

    cout << pop1() << endl;
    cout << pop2() << endl;
}