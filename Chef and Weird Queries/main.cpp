#include <iostream>
using namespace std;

long CheckQuery(long n){
    long result=0;
    for(long i=1;i*i<n;i++){
        long temp = n - i*i;
        if(temp > 700){
            result += 700;
        }else{
            result += temp;
        }
        cout<<result<<endl;
    }
    return result;
}

int main(){
    int t;
    cin>>t;
    long y;
    for(int i=0;i<t;i++){
        cin>>y;
        cout<<CheckQuery(y)<<endl;
    }
    return 0;
}