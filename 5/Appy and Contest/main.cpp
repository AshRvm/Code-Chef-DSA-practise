#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin>>t;
    while(t--){
        ll n,a,b,k;
        cin>>n>>a>>b>>k;
        ll temp = (a*b)/__gcd(a,b);
        if((n/a) + (n/b) - 2*(n/temp) >= k) cout<<"Win"<<endl;
        else cout<<"Lose"<<endl;
    }
}