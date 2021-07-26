#include <iostream>
#include <set>
#include <vector>
using namespace std;

void Primes(vector<int>& a){
    int size = a.size();
    for(int i=0;i<size;i++) a[i] = i+1;
    vector<int> b;
    vector<bool> c(size,true);
    c[0] = false;
    int index = 1;
    while(index < size){
        if(c[index] == true){
            int temp = a[index];
            for(int i=temp*temp;i<=size;i+=temp) c[i-1] = false;
        }
        index++;
    }
    for(int i=0;i<size;i++) if(c[i] == true) b.push_back(i+1);
    a = b;
    b.clear();
    c.clear();
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(100);
        Primes(a);
        set<int> sum;
        for(int i=0;i<a.size()-1;i++){
            if(a[i] > 14) break;
            for(int j=i+1;j<a.size();j++){
                int temp = a[i]*a[j];
                if(temp > 200) break;
                else sum.insert(temp);
            }
        }
        int count = 0;
        for(set<int>::iterator itr = sum.begin(); itr != sum.end(); itr++){
            if(sum.find(n-*itr) != sum.end()){
                cout<<"YES"<<endl;
                break;
            }else{
                count++;
                if(count > (sum.size()+1)/2){
                    cout<<"NO"<<endl;
                    break;
                }
            }

        }
    }
}