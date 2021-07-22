#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<ll> a(n);
        unordered_map<ll,int> umap;
        priority_queue<ll, vector<ll>, greater<ll> > pq;
        ll count=0;
        ll end = n-1, pins = 0;
        for(int i=0;i<n;i++){
            cin>>a[i];
            umap.insert(make_pair(a[i],i));
            pq.push(a[i]);
        }
        while(end >= 0){
            ll min = pq.top();
            pq.pop();
            int index = umap.find(min)->second;
            if(index > end) continue;
            count += (min-pins)*(end+1);
            pins = min;
            end = index-1;
        }
        cout<<count<<endl;
    }
}