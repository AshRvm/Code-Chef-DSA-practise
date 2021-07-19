#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,z;
        cin>>n>>z;
        priority_queue<int> a;
        for(int i=0;i<n;i++){
            int temp;
            cin>>temp;
            a.push(temp);
        }
        int result = 0;
        while(!a.empty()){
            result ++;
            int temp = a.top();
            z -= temp;
            if(z <= 0) break;
            a.pop();
            if(temp/2 != 0) a.push(temp/2);
        }
        if(z <= 0) cout<<result<<endl;
        else cout<<"Evacuate"<<endl;
    }
}