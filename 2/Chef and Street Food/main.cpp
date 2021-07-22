#include <iostream>
#include <queue>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        priority_queue<int> pq;
        for(int i=0;i<n;i++){
            int s,p,v;
            cin>>s>>p>>v;
            pq.push(v*(p/(s+1)));
        }
        cout<<pq.top()<<endl;
    }
}