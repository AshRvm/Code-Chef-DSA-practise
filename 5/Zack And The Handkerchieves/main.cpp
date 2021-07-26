#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int l,b;
        cin>>l>>b;
        cout<<__gcd(l,b)<<endl;
    }
}