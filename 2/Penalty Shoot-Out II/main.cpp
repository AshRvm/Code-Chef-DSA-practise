#include <iostream>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        int count = 0;
        int hit1=0, hit2=0, miss1=0, miss2=0;
        while(count < 2*n){
            if(count%2 == 0){
                if(s[count] == '1') hit1++;
                else miss1++;
            }else{
                if(s[count] == '1') hit2++;
                else miss2++;
            }
            count++;
            if((hit1 + miss2 > n) || (hit2 + miss1 > n)) break;
        }
        cout<<count<<endl;
    }
}