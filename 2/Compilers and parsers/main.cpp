#include <iostream>
#include <string>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int count = 0;
        int result = 0;
        int i=0;
        while(i < s.size()){
            if(s[i] == '<')count++;
            else count--;
            if(count<0) break;
            if(count == 0) result = i+1;
            i++;
        }
        cout<<result<<endl;
    }
}