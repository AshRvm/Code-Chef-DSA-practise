#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> a(n,0), b(m,0);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<m;i++) cin>>b[i];
    int minB=(10e9 + 1), maxA=-(10e9 + 1);
    int minI=0,maxI=0;
    for(int i=0;i<n;i++){
        if(a[i] > maxA){
            maxA = a[i];
            maxI = i;
        }
    }
    for(int i=0;i<m;i++){
        if(b[i] < minB){
            minB = b[i];
            minI = i;
        }
    }
    for(int i=0;i<n;i++) cout<<i<<" "<<minI<<endl;
    for(int i=0;i<minI;i++) cout<<maxI<<" "<<i<<endl;
    for(int i=minI+1;i<m;i++) cout<<maxI<<" "<<i<<endl;
}