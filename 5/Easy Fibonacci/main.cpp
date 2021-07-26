#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

typedef long double ld;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int tempPow = 0;
        while(n > 1){
            n = n/2;
            tempPow++;
        }
        int power = 1<<tempPow;
        ld temp1,temp2;
        temp1 = 1 + sqrt((ld)5);
        temp2 = 1 - sqrt((ld)5);
        temp1 = pow(temp1/2, power);
        temp2 = pow(temp2/2, power);
        ld final = (temp1 - temp2)/sqrt(5);
        cout<<final<<endl;
    }
}