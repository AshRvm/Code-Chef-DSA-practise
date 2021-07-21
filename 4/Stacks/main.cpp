#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a;
        while(n--){
            int temp;
            cin>>temp;
            auto itr = upper_bound(a.begin(),a.end(),temp);
            if(itr == a.end()) a.push_back(temp);
            else *itr = temp;
        }
        cout<<a.end()-a.begin()<<" ";
        for(auto i=a.begin();i != a.end();i++){
            cout<<*i<<" ";
        }
        cout<<endl;
    }
}