#include<bits/stdc++.h>
using namespace std;
class minHeap{
private:
    int *arr;
    int size;
    int capacity;

public:
    minHeap(int c)
    {
        arr = new int[c];
        capacity = c;
        size = 0;
    }
    int left(int i) { return 2 * i + 1; }
    int right(int i) { return 2 * i + 2; }
    int parent(int i) { return (i-1) / 2; }
    void insert(int key){
        if(size==capacity)
            return;
        size++;
        arr[size - 1] = key;
        int x = size - 1;
        while (x > 0 && key < arr[parent(x)])
        {
            arr[x]=arr[parent(x)];
            x = parent(x);
        }
        arr[x] = key;
    }
    void i_minheapify(int i){
        while(i<size){
        int lc = left(i), rc = right(i);
        int smallest=i;
        if (lc < size && arr[lc]<arr[i])
            smallest = lc;
        if(rc<size&& arr[rc]<arr[smallest])
            smallest = rc;
        if(smallest!=i){
            swap(arr[i], arr[smallest]);
            i=smallest;
        }
        else
            break;
        }
    }
    int extractMin(){
        if(size==0)
            return -1;
        if(size==1){
            size--;
            return arr[0];
        }
        int x = arr[0];
        arr[0] = arr[size - 1];
        size--;
        i_minheapify(0);
        return x;
    }
    void decreaseKey(int i,int key){
        arr[i] = key;
        while(i>=0&&arr[i]<arr[parent(i)]){
            swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }
    }
    void Delete(int i){
        decreaseKey(i, INT_MIN);
        extractMin();
    }
    void build_heap(int arr[],int n){
        for (int i = (n - 1) / 2; i >=0;i++){
            i_minheapify(i);
        }
    }
    void print(){
        for (int i = 0; i < size;i++)
            cout << arr[i] << " ";
    }
};
int main(){
    minHeap mh(20);
    int arr[] = {100,80,70,20,40,35,32,10};
    int i=0;
    while (i<8){
        mh.insert(arr[i]);
        i++;
    }
    mh.print();
    cout<<endl;
    // cout << mh.extractMin() << endl;
    // mh.decreaseKey(3, 41);
    mh.Delete(3);
    mh.print();
}
