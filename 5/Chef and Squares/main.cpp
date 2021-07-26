#include <iostream>
#include <cmath>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        if((n == 1) || (n == 2)){
            cout<<-1<<endl;
            continue;
        }
        int temp = (int)sqrt((double)n);
        if(temp*temp == n) temp--;
        ll min = -1;
        for(int i=temp;i>0;i--){
            if(n%i == 0){
                if((i + n/i)%2 == 0){
                    min = ((n/i)-i)/2;
                    break;
                }
            }
        }
        if(min == -1) cout<<-1<<endl;
        else cout<<min*min<<endl;
    }
}