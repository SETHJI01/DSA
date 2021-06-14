#include<bits/stdc++.h>
using namespace std;
bool isPrime(int n){
    for (int i = 2; i * i <= n;i++){
        if(n%i==0)
            return false;
    }
    return true;
}
bool isValid(int a,int b){
    int count = 0;
    while(a>0){
        if(a%10!=b%10)
            count++;
        a /= 10, b /= 10;
    }
    if(count==1)
        return true;
    return false;
}
void buildGraph(vector<int> arr[]){
    vector<int> primes;
    for (int i = 1000; i <= 9999; i++){
        if(isPrime(i))
            primes.push_back(i);
    }
    for (int i = 0; i <primes.size(); i++){
        for (int j = i + 1; j <primes.size(); j++){
            int a = primes[i];
            int b = primes[j];
            if (isValid(a,b)){
                arr[a].push_back(b);
                arr[b].push_back(a);
            }
        }
    }
}
void bfs(vector<int> arr[],bool vis[],int dist[],int src){
    queue<int> q;
    q.push(src);
    dist[src] = 0;
    vis[src] = 1;
    while(!q.empty()){
        int temp = q.front();
        q.pop();
        for(int child:arr[temp]){
            if(!vis[child]){
                vis[child] = 1;
                dist[child] = dist[temp] + 1;
                q.push(child);
            }
        }
    }
}
int main(){
	int t;
	cin>>t;
    vector<int> arr[10000];
    bool vis[10000];
    int dist[10000];
    buildGraph(arr);
	while(t--){
        int a, b;
        cin >> a >> b;    
        for (int i = 1000; i <= 9999;i++){
            dist[i] = -1;
            vis[i] = false;
        }
        bfs(arr,vis,dist,a);
        if(dist[b]==-1)
            cout << "Impossible" << endl;
        else
            cout <<dist[b]<< endl;
	}
}