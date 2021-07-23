#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>
using namespace std;

typedef long long ll;

int main(){
    int n,k;
    int mod = (int)(1e9 + 7);
    ll count = 1;
    cin>>n>>k;
    queue<int> a;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        a.push(temp);
    }
    unordered_map<int,vector<int> > umap;
    vector<int> b;
    for(int i=0;i<n;i++){
        int temp = a.front();
        a.pop();
        vector<int>::iterator itr = upper_bound(b.begin(),b.end(),temp);
        vector<int>::iterator lb = lower_bound(b.begin(),b.end(),temp);
        if((itr == b.end()) && (lb == itr)){
            b.push_back(temp);
            // cout<<"TEEEEEEEEEEEEEEEEEEEEEST"<<endl;
        }
        else if(itr != b.end()){
            int tempIndex = b.end()-itr;
            for(int k=0;k<tempIndex;k++){
                int tempValue = b.back();
                b.pop_back();
                unordered_map<int,vector<int> >::iterator itr2 = umap.find(tempValue);
                for(int j=0;j<itr2->second.size();j++){
                    // cout<<"COUNT BEFORE :"<<count<<endl;
                    // cout<<"i :"<<i<<" :: other index :"<<itr2->second[j]<<endl;
                    count = count*(ll)(i+1 - itr2->second[j]);
                    // cout<<"COUNT AFTER :"<<count<<endl;
                    count %= mod;
                }
                umap.erase(itr2);
            }
            if(lb == itr) b.push_back(temp);
        }
        if(umap.find(temp) == umap.end()){
            vector<int> tempVec(1,i);
            umap.insert(make_pair(temp,tempVec));
        }else{
            umap.find(temp)->second.push_back(i);
        }
    }
    cout<<count<<endl;
}