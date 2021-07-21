#include <iostream> 
#include <vector>
using namespace std;

void getParent(vector<int> p, int i){
    while(p[i] != i) i = p[i];
    cout<<i+1<<endl;
}

int main(){
    int n,q;
    cin>>n>>q;
    vector<int> a(n),p(n);
    cin>>a[0];
    p[0] = 0;
    for(int i=1;i<n;i++){
        cin>>a[i];
        if(a[i]%a[i-1] == 0) p[i]=i-1;
        else p[i] = i;
    }
    for(int i=0;i<q;i++){
        int temp1,temp2;
        cin>>temp1>>temp2;
        temp2--;
        if(temp1 == 1){
            int temp3;
            cin>>temp3;
            if(temp3%a[temp2-1] == 0) p[temp2] = temp2-1;
            else p[temp2] = temp2;
        }else if(temp1 == 2){
            getParent(p,temp2);
        }
    }
    return 0;
}