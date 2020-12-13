#include <iostream>
using namespace std;

int Min(int* array, int n){
    int min = array[0];
    int index = 0;
    for(int i=1;i<n;i++){
        if(min > array[i]){
            min = array[i];
            index = i;
        }
    }
    return index;
}

int main(){
    int t,n;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n;
        int* array = new int[n];
        for(int j=0;j<n;j++){
            cin>>array[j];
        }
        cout<<Min(array, n)+1<<endl;
        delete array;
    }
    return 0;
}