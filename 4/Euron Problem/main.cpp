#include <iostream> 
#include <vector>
using namespace std;

int merge(vector<int>& a, vector<int>& b, int s1, int f1, int s2, int f2){
    int i = s1;
    int temp1 = s1, temp2 = s2;
    int count = 0;
    while((temp1 <= f1) && (temp2 <= f2)){
        if(a[temp1] < a[temp2]){
            b[i] = a[temp1];
            temp1++;
        }else{
            b[i] = a[temp2];
            temp2++;
            count += f1-temp1+1;
        }
        i++;
    }
    while(temp1<=f1){
        b[i] = a[temp1];
        temp1++;
        i++;
    }
    while(temp2<=f2){
        b[i] = a[temp2];
        temp2++;
        i++;
    }
    // cout<<"BLAH :";
    for(int i=s1;i<=f2;i++){
        // cout<<b[i]<<" ";
        a[i] = b[i];
    }
    // cout<<endl;
    return count;
}

int count(vector<int>& a, vector<int>& b, int s, int f){
    if(s == f) return 0;
    int result = 0;
    int mid = (s+f)/2;
    int c1 = count(a,b,s,mid), c2 = count(a,b,mid+1,f);
    result = c1 + c2 + merge(a,b,s,mid,mid+1,f);
    // cout<<"TEST: "<<c1<<" "<<c2<<" "<<(result-c1-c2)<<" :: "<<a[s]<<" "<<a[f]<<endl;
    return result;
}

int main(){
    int n;
    cin>>n;
    vector<int> a(n), b(n);
    for(int i=0;i<n;i++) cin>>a[i];
    cout<<count(a,b,0,n-1)<<endl;
}