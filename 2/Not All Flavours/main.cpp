#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> a(n);
        for(int i=0;i<n;i++) cin>>a[i];
        unordered_map<int,int> umap;
        for(int i=0;i<k;i++) umap.insert(make_pair(i+1,0));
        int max = 0;
        int count = 0;
        int end = 0;
        int length = 0;
        umap.find(a[0])->second++;
        count++;
        end = 1;
        length = 1;
        while((count < k) && (end < n)){
            if((umap.find(a[end])->second == 0) && (count == k-1)){
                if(length > max) max = length;
                break;
            }else if(umap.find(a[end])->second == 0) count++;
            umap.find(a[end])->second ++;
            length++;
            end++;
        }
        if(end == n){
            cout<<n<<endl;
            continue;
        }
        for(int i=1;i<n;i++){
            umap.find(a[i-1])->second--;
            length--;
            if(umap.find(a[i-1])->second > 0) continue;
            count--;
            while((count < k) && (end < n)){
                if((umap.find(a[end])->second == 0) && (count == k-1)){
                    if(length > max) max = length;
                    break;
                }else if(umap.find(a[end])->second == 0) count++;
                umap.find(a[end])->second ++;
                length++;
                end++;
            }
            if(end == n) max = (max > length) ? max : length;
        }
        cout<<max<<endl;
    }
}