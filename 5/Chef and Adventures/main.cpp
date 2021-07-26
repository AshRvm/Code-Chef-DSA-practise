#include <iostream>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m,x,y;
        cin>>n>>m>>x>>y;
        if(((n-1)%x == 0) && ((m-1)%y == 0)) cout<<"Chefirnemo"<<endl;
        else if(((n-2)%x == 0) && ((m-2)%y == 0) && (n>1) && (m>1)) cout<<"Chefirnemo"<<endl;
        else cout<<"Pofik"<<endl;
    }
}