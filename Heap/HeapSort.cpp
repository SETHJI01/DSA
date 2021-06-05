#include<bits/stdc++.h>
using namespace std;
void heapify(int arr[],int n,int i){
    int lc = 2 * i + 1;
    int rc = 2 * i + 2;
    int largest = i;
    if (lc < n&&arr[lc]>arr[largest])
        largest = lc;
    if (rc < n&&arr[rc]>arr[largest])
        largest = rc;
    if(largest!=i){
        swap(arr[i], arr[largest]);
        heapify(arr, n,largest);
    }
}
void heapsort(int arr[],int n){
    for (int i = (n -1)/2 ; i >= 0;i--)
        heapify(arr,n,i);
    for (int i = n - 1; i > 0;i--){
        swap(arr[0], arr[i]);
        heapify(arr,i,0); //heapify the remaining
    }
}
int main(){
    // int n = 8;
    // int arr[] = {20, 25, 10, 11, 1, 33, 79, 50};
    int arr[] = { 12, 11, 13, 5, 6, 7 };
    int n = sizeof(arr) / sizeof(arr[0]);
    heapsort(arr, n);
    for (int i = 0; i < n;i++)
        cout << arr[i] << " ";
}